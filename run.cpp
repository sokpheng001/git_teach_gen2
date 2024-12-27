#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

class StudentRecord{
    private:
        int id;
        string studentName;
        // subject score
        double cProgram;
        double dataStructure;
        double networking;
        double english;
    public:
        void setId(int id){
            this->id = id;
        }
        void setStudentName(string studentName){
            this->studentName = studentName;
        }
        void cProrgram(double cProgram){
            this->cProgram = cProgram;
        }
        void setDataStructure(double dataStructure){
            this->dataStructure = dataStructure;
        }
        void setNetworking(double networking){
            this->networking = networking;
        }
        void setEnglish(double english){
            this->english = english;
        }
        void setSubjectScore(double cProgram, double dataStructure, double networking, double english){
            this->cProgram = cProgram;
            this->dataStructure = dataStructure;
            this->networking = networking;
            this->english = english;
        }
        int getId(){
            return id;
        }
        string getStudentName(){
            return studentName;
        }
        double getCProgram(){
            return cProgram;
        }
        double getDateStructure(){
            return dataStructure;
        }
        double getNetworking(){
            return networking;
        }
        double getEnglish(){
            return english;
        }
        // constructor
        StudentRecord(){};
        StudentRecord(int id, string studentName, double cProgram, double dataStructure, double networking, double english){
            this->id = id;
            this->studentName = studentName;
            this->cProgram = cProgram;
            this->dataStructure = dataStructure;
            this->networking = networking;
            this->english = english;
        }
        // getInfo
        void getStudentRecordInfo(){
            cout<<"ID: "<<this->id<<endl;
            cout<<"Name: "<<this->studentName<<endl;
            cout<<"C Program: "<<this->cProgram<<endl;
            cout<<"Data Structure: "<<this->dataStructure<<endl;
            cout<<"Networking: "<<this->networking<<endl;
            cout<<"English: "<<this->english<<endl;
        }
};
vector<string> split(string line, char delimiter){
    vector<string> tokens;
    string token;
    for(char c: line){
        if(c == delimiter){
            tokens.push_back(token);
            token = "";
        } else {
            token += c;
        }
    }
    tokens.push_back(token);
    return tokens;
}
void writeStudentRecord(StudentRecord &record){
    ofstream file("studentRecord.txt", ios::app);
    if(file.is_open()){
        file << record.getId() << "," 
        << record.getStudentName() << "," 
        << record.getCProgram() << "," 
        << record.getDateStructure() << "," 
        << record.getNetworking() << ","
        << record.getEnglish() << endl;
        file.close();
    } else {
        cout << "Unable to open file";
    }
}
vector<StudentRecord> readStudentRecord(){
    ifstream file("studentRecord.txt");
    vector<StudentRecord> students;
    if(file.is_open()){
        string line;
        while(getline(file, line)){
            vector<string> data = split(line, ',');
            int id = stoi(data[0]);
            string studentName = data[1];
            double cProgram = stod(data[2]);
            double dataStructure = stod(data[3]);
            double networking = stod(data[4]);
            double english = stod(data[5]);
            StudentRecord record(id, studentName, cProgram, dataStructure, networking, english);
            students.push_back(record);
        }
        file.close();
    }
    return students;
}
void removeStudentRecord(int recordId){
    vector<StudentRecord> students = readStudentRecord();
    ofstream file("studentRecord.txt");
    if(file.is_open()){
        for(StudentRecord &record: students){
            if(record.getId()!= recordId){
                file << record.getId() << "," 
                << record.getStudentName() << "," 
                << record.getCProgram() << "," 
                << record.getDateStructure() << "," 
                << record.getNetworking() << ","
                << record.getEnglish() << endl;
            }
        }
        file.close();
    } else {
        cout << "Unable to open file";
    }
}

int main(){
    StudentRecord studentRecord(4, "Kim Chansokpheng",70.0,70.0,70.0,70.0);
    writeStudentRecord(studentRecord);
    vector<StudentRecord> students = readStudentRecord();
    for(StudentRecord &record: students){
        record.getStudentRecordInfo();
    }
    removeStudentRecord(3);
    cout<<"\033[43mAfter deleted student data:\033[0m \n";
    students = readStudentRecord();
    for(StudentRecord &record: students){
        record.getStudentRecordInfo();
    }
    return 0;
}