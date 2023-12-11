#include "OutOfBoundsException.hpp"
#include "String.hpp"

String::String(){
    this -> size_ = 0;
    this -> char_ = new char[1];
    char_[0] = '\0';
}

String::String(const char* chars){
    this -> size_ = 0;
    unsigned int temp = 0;
    while (chars[temp] != '\0'){
        temp++;
    }
    this -> char_ = new char[temp+1];
    while (chars[size_] != '\0'){
        char_[size_] = chars[size_];
        size_++;
    }
    char_[size_] = '\0';
}

String::String(const String& s){
    this -> size_ = s.size_;
    this -> char_ = new char[size_+1];
    unsigned int temp = 0;
    while (s.char_[temp]!= '\0'){
        char_[temp] = s.char_[temp];
        temp++;
    }
    char_[temp] = '\0';
}

String::~String() noexcept{
    delete[] char_;
}

String& String::operator=(const String& s){
    if (this == &s){
        return *this;
    }
    delete[] char_;
    size_ = s.size_;
    char_ = new char[size_ + 1];
    unsigned int temp = 0;
    while (s.char_[temp]!= '\0'){
        char_[temp] = s.char_[temp];
        temp++;
    }
    char_[temp] = '\0';
    return *this;
}


String String::concatenate(const String& s) const{
    String answer = String{*this};
    answer.append(s);
    return answer;
}

bool String::contains(const String& substring) const noexcept{
    unsigned int index = 0;
    unsigned int same_number = 0;
    while(this -> char_[index] != '\0'){
        if (this -> char_[index] == substring.char_[0]){
            for (int i = 0; i < substring.size_;i++){
                if (this -> char_[index+i] == substring.char_[i]){
                    same_number++;
                }
                else{
                    same_number = 0;
                    break;
                }
            }
        }
        if (same_number == substring.size_){
            return true;
        }
        index++;
    }
    return false;
}

bool String::isEmpty() const noexcept{
    if (this -> size_ != 0 || this -> char_[0] != '\0'){
        return false;
    }
    return true;
}

unsigned int String::length() const noexcept{
    return this -> size_;
}

String String::substring(unsigned int startIndex, unsigned int endIndex) const{
    if (startIndex >= this -> size_ || endIndex >= this -> size_){
        throw OutOfBoundsException();
    }
    if (endIndex <= startIndex){
        String answer{};
        return answer;
    }
    char* temp = new char[endIndex - startIndex+1];
    for (unsigned int i = startIndex; i < endIndex; i++){
        temp[i - startIndex] = this -> char_[i];
    }
    temp[endIndex - startIndex] = '\0';
    const char* answer = temp;
    String final_answer{answer};
    delete[] temp;
    return final_answer;
}
