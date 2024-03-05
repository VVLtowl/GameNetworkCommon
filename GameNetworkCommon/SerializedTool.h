#pragma once
#include <string>



struct CommonStruct {
    long len;
    void* buff;
};

char* EncodeCommonStruct(const CommonStruct& commonStruct, int& outLen);
bool DecodeCommonStruct(const char* strBuff, long maxLen, CommonStruct& outCommonStruct);


//common msg struct
//totalLen=4+4+?
const size_t LEN_MSG_CONTENT = 4;
struct MsgContent
{
    int BHID = -1;//for edit command id
    long DataLen = 0;
    void* Data = nullptr;
};

//net msg buf len
const int LEN_MSG_DATA_DEFAULT = 1024;

//make MsgContent to char
char* EncodeMsgContent(const MsgContent& msg, char* outBuf=nullptr);

//make char to MsgContent
bool DecodeMsgContent(const char* strBuff, MsgContent& outMsg);
