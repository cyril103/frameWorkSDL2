#include "App_manager.h"

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    AppManager *app = App_instance();
    app->run();
    App_realease();
    memory_leak_check();
    return EXIT_SUCCESS;
}