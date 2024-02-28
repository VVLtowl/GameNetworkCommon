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
    long DataLen;
    void* Data;
};

//net msg buf len
const int LEN_MSG_TOOL = 1024;

//make MsgContent to char
char* EncodeMsgContent(const MsgContent& msg, char* outBuf=nullptr, int msglen= LEN_MSG_TOOL);

//make char to MsgContent
bool DecodeMsgContent(const char* strBuff, MsgContent& outMsg);
