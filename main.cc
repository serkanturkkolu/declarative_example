
#include <iostream>
#include <unordered_map>

struct Empty
{};

using Func = void(*)(const Empty*);
struct Declarative{
    Func func;
    std::unique_ptr<Empty> param;
};
using Map=std::unordered_map<std::string,Declarative>;

struct Message1Info : Empty{
    char header{'a'};
    char message_type{'b'};
    char message_id{'c'};
};

struct Message2Info : Empty{
    char header1{'d'};
    char header2{'e'};
    char message_type{'f'};
};

int main(){  
    
    Map map{};
    map.emplace("message1", Declarative{[](const Empty* empty){
        const Message1Info* msg = (const Message1Info*)empty;
        std::cout << "Message1: " << msg->header << msg->message_id << msg->message_type << std::endl;
    },std::make_unique<Message1Info>()});

    map.emplace("message2", Declarative{[](const Empty* empty){
        const Message2Info* msg = (const Message2Info*)empty;
        std::cout << "Message2: " << msg->header1 << msg->header2 << msg->message_type << std::endl;
    },std::make_unique<Message2Info>()});

    const auto &message1 = map.at("message1");
    message1.func(message1.param.get());
    const auto &message2 = map.at("message2");
    message2.func(message2.param.get());
    return 0;
}