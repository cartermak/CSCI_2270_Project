#include "project.hpp"
#include "UI.h"

JNIEXPORT void JNICALL Java_UI_constructConnection(JNIEnv *env, jobject obj)
{
    Connection::Connection();
}

JNIEXPORT jboolean JNICALL Java_UI_addPart(JNIEnv *env, jobject obj, jstring partNum, jstring count, jstring name, jstring description)
{
    bool t = true;
    bool y = true;
    const char *s = env->GetStringUTFChars(partNum, 0);
    std::string str(s);
    env->ReleaseStringUTFChars(partNum, s);
    env->ReleaseStringUTFChars(count, s);
    const char *s = env->GetStringUTFChars(count, 0);
    std::string st(s);
    const char *s = env->GetStringUTFChars(name, 0);
    std::string Name(s);
    const char *s = env->GetStringUTFChars(description, 0);
    std::string description(s);
    int partnumber;
    int Count;
    try
    {
        partnumber = stoi(str);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        t = false;
    }
    try
    {
        Count = stoi(st);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        y = false;
    }
    if(!y || !t){
        return false;
    }
    // else return Connection::addPart(partnumber,Count, Name, description);
    
}
