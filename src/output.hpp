void startOutputMode(){
    bool answer;
    int tmp;
    std::cout << "Do you want to start output mode? 1(Yes) 0(No):";
    std::cin >> tmp;
    answer = static_cast<bool>(tmp);
    if(answer == static_cast<bool>(1)){
        readFromPipe();
    }
}

Packet readFromPipe(Packet data){
    return Packet;
}
