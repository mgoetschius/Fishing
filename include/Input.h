#ifndef INPUT_H
#define INPUT_H


class Input
{
    public:
        Input();
        virtual ~Input();
        //const int NUM_KEYS = 256;
        enum keyValues
        {
           KEY_A = 65,
           KEY_D = 68,
           KEY_W = 87,
           KEY_S = 83,
           KEY_Q = 81,
           KEY_Z = 90,
           KEY_E = 69,
           KEY_C = 67,
           KEY_P = 80
        };
        static void setKeyTrue(int key);
        static void setKeyFalse(int key);
        static bool getKey(int key);
    protected:
    private:
        static bool keys[];

};

#endif // INPUT_H
