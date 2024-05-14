#pragma once

#include <iostream>

using namespace std;

class Person;
class Product;

template<class T>
class index;

struct Field {
public:
    char szFieldRepresentation; //The Field is Fixed length 'F', Length indicator 'L' or Delimiter 'D'
    char length; //Length of the Field => Fixed length or Length indicator => sizeof(datatype) or 2
    char delimiter; //Delimiter of the Field => '|'
};

// Abstract class designed to support variablelength records
// Fields may be of a variety of types
class VariableLengthBuffer {
private:
    Field* m_recordFields; // Array of Fields (Record) that allocates in heap with m_iFieldsCount
    int m_iRecordSize, //The Size of the Record
        m_iNextByte,
        m_iFieldsCount; // Number of Fields of the Record
    char* pRecord; //Pointer to record

public:
    VariableLengthBuffer();

    void init(int iFieldsCount);

    void AddField(int index, char szType, char delimiter);

    void AddField(int index, char szType, int length);

    bool WriteHeader(ostream&) const;

    bool ReadHeader(istream&);

    void Clear(int recordSize = -1); // clear fields from buffer

    bool Write(ostream&) const;

    bool Read(istream&);

    bool PackFixLen(void* lpData, int dataLength, int fieldLength);

    bool PackDelimeted(void* lpData, int dataLength, char delimiter);

    bool PackLength(void* lpData, short dataLength, char lengthIndicatorSize);

    bool Pack(int, void*, int);

    bool UnpackFixLen(char* lpData, int fieldLength);

    bool UnpackDelimeted(char* lpData, char delimiter, bool bIsText = false);

    bool UnpackLength(char*, char lengthIndicatorSize, bool bIsText = false);

    bool Unpack(int, char*, bool bIsText = false);
};