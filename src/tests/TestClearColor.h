//
// Created by hosung on 21. 6. 3..
//

#ifndef STUDY_TESTCLEARCOLOR_H
#define STUDY_TESTCLEARCOLOR_H

#include "Test.h"

namespace test{
    class TestClearColor : public Test{
    public:
        TestClearColor();
        ~TestClearColor();

        void OnUpdate(float deltaTime) override;
        void OnRender() override;
        void OnImGuiRender() override;

    private:
        float m_ClearColor[4];
    };
}


#endif //STUDY_TESTCLEARCOLOR_H
