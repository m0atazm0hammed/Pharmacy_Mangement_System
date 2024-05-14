#include "varlen.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

//Class VariableLengthBuffer
//public methods

//Default Constructor
VariableLengthBuffer::VariableLengthBuffer() {
    m_recordFields = 0;
    m_iRecordSize = 0;
    m_iNextByte = 0;
    m_iFieldsCount = 0;
    pRecord = 0;
}

//Initialize the buffer in the memory
void VariableLengthBuffer::init(int m_iFieldsCount) {
    this->m_iFieldsCount = m_iFieldsCount;
    m_recordFields = new Field[this->m_iFieldsCount];
}

//Add Field in the specific index in the record - Add Field with delimiter
void VariableLengthBuffer::AddField(int index, char szType, char delimiter) {
    m_recordFields[index].szFieldRepresentation = szType;//szType --> D
    m_recordFields[index].delimiter = delimiter;//delimiter --> |
}

//Add Field in the specific index in the record - Add Field with length
void VariableLengthBuffer::AddField(int index, char szType, int length) {
    m_recordFields[index].szFieldRepresentation = szType;//szTpe --> F or L
    m_recordFields[index].length = length;//length --> length of field
}

bool VariableLengthBuffer::WriteHeader(ostream& stream) const {
    short DelHeader = -1;

    stream.seekp(0, ios::end);
    if (stream.tellp() == 0) {
        stream.write((char*)&m_iFieldsCount, 1);//Write number of fields in the file : 7
        if (stream.fail())
            return false;

        for (int i = 0; i < m_iFieldsCount; i++) {//m_iFieldsCount = 7 - i = 0:6
            stream.write(&m_recordFields[i].szFieldRepresentation, 1);
            if (stream.fail())
                return false;

            if (m_recordFields[i].szFieldRepresentation == 'F' || m_recordFields[i].szFieldRepresentation == 'L')
                stream.write(&m_recordFields[i].length, 1);
            else if (m_recordFields[i].szFieldRepresentation == 'D')
                stream.write(&m_recordFields[i].delimiter, 1);

            if (stream.fail())
                return false;
        }
        stream.write((char*)&DelHeader, sizeof(DelHeader));
        if (stream.fail())
            return false;
    }
    return true;
}

//Read the header and check for consistency and seek the cursor to the first record
bool VariableLengthBuffer::ReadHeader(istream& stream) {
    short DelHeader = -1;

    stream.read((char*)&m_iFieldsCount, 1); //Read number of fields from the file : 7
    if (stream.fail())
        return false;

    m_recordFields = new Field[m_iFieldsCount]; //New record to read and store the header into it

    for (int i = 0; i < m_iFieldsCount; i++) {
        stream.read(&m_recordFields[i].szFieldRepresentation, 1);
        if (stream.fail())
            return false;

        if (m_recordFields[i].szFieldRepresentation == 'F' || m_recordFields[i].szFieldRepresentation == 'L')
            stream.read(&m_recordFields[i].length, 1);
        else if (m_recordFields[i].szFieldRepresentation == 'D')
            stream.read(&m_recordFields[i].delimiter, 1);

        if (stream.fail())
            return false;
    }
    stream.read((char*)&DelHeader, sizeof(DelHeader));
    if (stream.fail())
        return false;

    return true;
}


void VariableLengthBuffer::Clear(int recordSize /*= -1*/) {
    m_iNextByte = 0;
    m_iRecordSize = 0;

    if (pRecord != 0)
        delete pRecord;

    if (recordSize != -1)
        pRecord = new char[recordSize];
    else
        pRecord = 0;
}

bool VariableLengthBuffer::Write(ostream& stream) const {
    // write the length and buffer into the stream
    stream.write((char*)&m_iRecordSize, sizeof(m_iRecordSize));
    if (stream.fail())
        return false;

    stream.write(pRecord, m_iRecordSize);
    return !stream.fail();
}

bool VariableLengthBuffer::Read(istream& stream) {
    Clear(m_iRecordSize);

    stream.read((char*)&m_iRecordSize, sizeof(m_iRecordSize));
    if (stream.fail())
        return false;

    pRecord = new char[m_iRecordSize];
    stream.read(pRecord, m_iRecordSize);
    return !stream.fail();
}


bool VariableLengthBuffer::PackFixLen(void* lpData, int dataLength, int fieldLength) {
    memset(pRecord + m_iNextByte, 0, fieldLength);
    //The memset() function in C++ copies a single character for a specified number of time to an object.
    if (dataLength > fieldLength)
        dataLength = fieldLength;

    memcpy(&pRecord[m_iNextByte], lpData, dataLength);

    m_iNextByte += fieldLength;
    m_iRecordSize = m_iNextByte;

    return true;
}

bool VariableLengthBuffer::PackDelimeted(void* lpData, int length, char delimiter) {
    memcpy(&pRecord[m_iNextByte], lpData, length);
    pRecord[m_iNextByte + length] = delimiter; // add delimeter

    m_iNextByte += length + 1;
    m_iRecordSize = m_iNextByte;

    return true;
}

bool VariableLengthBuffer::PackLength(void* lpData, short length, char lengthIndicatorSize) {
    memcpy(&pRecord[m_iNextByte], &length, lengthIndicatorSize);
    memcpy(&pRecord[m_iNextByte + lengthIndicatorSize], lpData, length);

    m_iNextByte += lengthIndicatorSize + length;
    m_iRecordSize = m_iNextByte;

    return true;
}

bool VariableLengthBuffer::Pack(int index, void* lpData, int dataLength) {
    if (m_recordFields[index].szFieldRepresentation == 'F')
        return PackFixLen(lpData, dataLength, m_recordFields[index].length);

    if (m_recordFields[index].szFieldRepresentation == 'D')
        return PackDelimeted(lpData, dataLength, m_recordFields[index].delimiter);

    return PackLength(lpData, dataLength, m_recordFields[index].length);
}

bool VariableLengthBuffer::UnpackFixLen(char* lpData, int fieldLength) {
    memcpy(lpData, pRecord + m_iNextByte, fieldLength);
    m_iNextByte += fieldLength;
    return true;
}

bool VariableLengthBuffer::UnpackDelimeted(char* lpData, char delimiter, bool bIsText /*= false*/) {
    int len = -1; // length of unpacked string

    for (int i = m_iNextByte; i < m_iRecordSize; i++) {
        if (pRecord[i] == delimiter) {
            len = i - m_iNextByte;
            break;
        }
    }

    if (len == -1)
        return false; // delimeter not found

    memcpy(lpData, pRecord + m_iNextByte, len);

    if (bIsText)
        lpData[len] = 0; // zero termination for string

    m_iNextByte += len + 1;

    return true;
}

bool VariableLengthBuffer::UnpackLength(char* lpData, char lengthIndicatorSize, bool bIsText /*= false*/) {
    short length;

    memcpy(&length, pRecord + m_iNextByte, lengthIndicatorSize);

    memcpy(lpData, pRecord + m_iNextByte + lengthIndicatorSize, length);
    if (bIsText)
        lpData[length] = 0;

    m_iNextByte += length + lengthIndicatorSize;
    return true;
}

bool VariableLengthBuffer::Unpack(int index, char* lpData, bool bIsText /*= false*/) {
    if (m_recordFields[index].szFieldRepresentation == 'F')
        return UnpackFixLen(lpData, m_recordFields[index].length);

    if (m_recordFields[index].szFieldRepresentation == 'D')
        return UnpackDelimeted(lpData, m_recordFields[index].delimiter, bIsText);

    return UnpackLength(lpData, m_recordFields[index].length, bIsText);
}