#include "HelloWorld.h"
#include "project.hpp"
JNIEXPORT void JNICALL Java_HelloWorld_displayHelloWorld(JNIEnv *, jobject)
{
    cout << "Hello World" << endl;
}