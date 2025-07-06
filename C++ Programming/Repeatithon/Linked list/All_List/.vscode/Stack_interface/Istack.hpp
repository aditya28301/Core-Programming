
class Istack{   

    public:
        virtual void push(size_t new_data) = 0;    
        virtual void pop() = 0;
        virtual void peek() = 0;
        virtual void display() = 0;
        virtual void empty() = 0;
        virtual bool isFull() = 0;
        virtual ~Istack(){ }
        static Istack* get_instance(size_t size);
        static void Release_instance(Istack* Istack);
};
