#include <iostream>
#include <cstdlib>
#include <string>
#include <stack>

class remove_para{
    private:
        std::string str;

    public:
        remove_para(std::string& ref_str) :  str(ref_str) { }

    void brute_remove_para(){
        std::stack<char> st;
        std::string ans("");

        for(int i = 0; i != str.size(); ++i){
            if(st.empty() == true){
                st.push(str[i]);
                continue;
            }
            if(st.empty() == false){
                if(st.top() == '(' && str[i] == ')'){
                    st.pop();
                }
                else{
                    st.push(str[i]);
                }

                if(st.empty() == false){
                    ans = ans + str[i];
                }
            }
        }
        std::cout <<"Remove Outermost string = " << ans << std::endl;
    }

    void optimal_remove_para(){
        int counter = 0;
        std::string ans("");
        for(int i = 0; i != str.size(); ++i){

            if(str[i] == ')'){
                counter = counter - 1;
            }
            if(counter != 0){
                ans = ans + str[i]; 
            }
            if(str[i] == '('){
                counter = counter + 1;
            }
        }
        std::cout <<"Remove Outermost string = " << ans << std::endl;
    }
};

int main(void){
    std::string str("(()())(())(()(()))");
    remove_para obj(str);
    obj.optimal_remove_para();
    std::cout <<"Programe terminated succesfully" << std::endl;
    return EXIT_SUCCESS;
}