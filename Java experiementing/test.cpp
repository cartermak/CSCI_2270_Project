#include "Simple.h"
#include "project.hpp"
JNIEXPORT void JNICALL Java_Simple_displayHelloWorld(JNIEnv *, jobject)
{
    cout << "Hello World" << endl;
}