#include "JSystem/JGeometry.h"

class MatrixTest {
public:
    void someFunction();

    TMtx34f mRotation;
};

void MatrixTest::someFunction() {
    mRotation.identity();
}