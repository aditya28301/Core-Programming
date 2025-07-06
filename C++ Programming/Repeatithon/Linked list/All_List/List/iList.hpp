// Typedefination statement
typedef int status_t;
typedef size_t data_t;

// Interface class decleratio

class Ilist{
	public:
		virtual ~Ilist() = 0 { };
		virtual void insert_start(data_t new_data) = 0;
		virtual void insert_end(data_t new_data) = 0;
		virtual void insert_after(data_t e_data, data_t new_data) = 0;
		virtual void insert_before(data_t e_data, data_t new_data) = 0;
		virtual void get_start() = 0;
		virtual void get_end() = 0;
		virtual void pop_start() = 0;
		virtual void pop_end() = 0;
		virtual void remove_data(data_t d_data) = 0;
		virtual void get_len() = 0;
		virtual void show_list() = 0;
		virtual status_t isEmpty() = 0;
        static Ilist* getInstance();
        static void released_instance(Ilist* obj);
};
