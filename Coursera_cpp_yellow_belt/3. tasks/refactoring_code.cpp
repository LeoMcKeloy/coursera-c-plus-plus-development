#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
public:
    Person(const string& name, const string& job) : Name(name), Job(job) {}

    string GetName() const {
        return Name;
    }
    string GetJob() const {
        return Job;
    }
    virtual void Walk(const string& destination) const = 0;

private:
    const string Name;
    const string Job;
};

class Student : public Person {
public:
    Student(const string& name, const string& favouriteSong) :
        Person(name, "Student"), FavouriteSong(favouriteSong) {}

    void Learn() const {
        cout << GetJob() << ": " << GetName() << " learns" << endl;
    }

    void Walk(const string& destination) const override {
        cout << GetJob() << ": " << GetName() << " walks to: " << destination << endl;
        SingSong();
    }

    void SingSong() const {
        cout << GetJob() << ": " << GetName() << " sings a song: " << FavouriteSong << endl;
    }

public:
    const string FavouriteSong;
};


class Teacher : public Person {
public:

    Teacher(const string& name, const string& subject) :
        Person(name, "Teacher"), Subject(subject) {}

    void Teach() const {
        cout << GetJob() << ": " << GetName() << " teaches: " << Subject << endl;
    }

    void Walk(const string& destination) const override {
        cout << GetJob() << ": " << GetName() << " walks to: " << destination << endl;
    }

public:
    const string Subject;
};


class Policeman : public Person {
public:
    Policeman(const string& name) : Person(name, "Policeman") {}

    void Check(Person& p) const {
        cout << GetJob() << ": " << GetName() << " checks " << p.GetJob() <<". " <<
        p.GetJob() << "s name is: " << p.GetName() << endl;
    }

    void Walk(const string& destination) const override {
        cout << GetJob() << ": " << GetName() << " walks to: " << destination << endl;
    }
};


void VisitPlaces(Person& p, vector<string> places) {
    for (auto it : places) {
        p.Walk(it);
    }
}


int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, {"Moscow", "London"});
    p.Check(s);
    VisitPlaces(s, {"Moscow", "London"});
    return 0;
}



