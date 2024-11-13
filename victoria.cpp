//
// Created by victoria on 11/13/24.
//

#include "header.h"

namespace
{
    pthread_t vt1;

    void *myfunc(void *data) {
        auto *s = static_cast<shared::SharedData*>(data);
        char str[] = "Good evening everyone!";
        memcpy(s, str, sizeof(str));
        std::print("{}", s->as_string_view());
        return nullptr;
    }

}



void victoria::init()
{
    pthread_create(&vt1, nullptr, myfunc, shared::data);
}

void victoria::run()
{
    pthread_join(vt1, nullptr);
}