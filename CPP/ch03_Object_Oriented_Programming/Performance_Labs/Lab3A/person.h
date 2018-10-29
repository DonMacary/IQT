#include <string>

class Person
{
private:
    std::string firstName, lastName, gender;
    int age;

public:
    Person(std::string firstName, std::string lastName, std::string gender, int age)
    {
        this->firstName = firstName;
        this->lastName = lastName;
        this->gender = gender;
        this->age = age;
    }
    ~Person()
    {
        
    }
    std::string getFName()
    {
        return firstName;
    }

   
    std::string getLName()
    {
        return lastName;
    }

    
    std::string getGender()
    {
        return gender;
    }
    int getAge()
    {
        return age;
    }

    void setFName(std::string fName)
    {
        this->firstName = fName;
    }

    void setLName(std::string LName)
    {
        this->lastName = LName;
    }

    void setGender(std::string gender)
    {
        this->gender = gender;
    }

    void setAge(int age)
    {
        this->age = age;
    }
};

