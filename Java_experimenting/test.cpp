#include "Simple.h"
#include "project.hpp"
#include <cstring>
#include <string>
using namespace std;
JNIEXPORT jint JNICALL Java_Simple_displayHelloWorld(JNIEnv *env, jobject obj, jstring string)
{
    const char *s = env->GetStringUTFChars(string, 0);
    std::string str(s);
    int y = 0;
    bool t = true;
    try
    {
        y = stoi(str);
    }
    catch (exception const &e)
    {
        cout << e.what() << endl;
        t = false;
    }
    if (t)
        y = y * 5;
    env->ReleaseStringUTFChars(string, s);
    cout << "Hello World lol" << endl;
    return y;
}