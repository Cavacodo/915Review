#include <bits/stdc++.h>
using namespace std;

unordered_map<int,string> st;
typedef struct student{
    int id;
    vector<int> status;
}stu;
typedef struct classInfo{
    int classTime;
    int studentNumber;
    vector<stu> student_info;
    unordered_map<int,stu> link;
    classInfo(int t,int n) : classTime(t), studentNumber(n) {}
    void insertStudentInfo(int id){
        int m = classTime;
        vector<int> v;
        while(m--){
            int status;
            cin >> status;
            v.push_back(status);
        }
        stu i = {id,v};
        student_info.push_back(i);
        link[id] = i;
    }
    void insertAllStudentInfo(){
        int t = studentNumber;
        while(t--){
            int id;
            cin >> id;
            insertStudentInfo(id);
        }
    }
    void getStudentStatus(int id){
        stu t = link[id];
        int arrival = 0,late = 0,leave = 0,absence = 0;
        for(int i = 0; i < classTime; i++){
            if(t.status[i] == 0) arrival++;
            else if(t.status[i] == 1) late++;
            else if(t.status[i] == 2) leave++;
            else absence++;
        }
        cout << "到课率:" << setprecision(2) << (double)(arrival/classTime) << endl;
        cout << "迟到率:" << setprecision(2) << (double)(late/classTime) << endl;
        cout << "请假率:" << setprecision(2) << (double)(leave/classTime) << endl;
        cout << "旷课率:" << setprecision(2) << (double)(absence/classTime) << endl;
    }
    void getOverallStatus(){
        int arrival = 0,late = 0,leave = 0,absence = 0;
        int al = classTime * studentNumber;
        for(int i = 0; i < studentNumber; i++){
            stu tmp = student_info[i];
            for(int j = 0; j < classTime; j++){
                if(tmp.status[j] == 0) arrival++;
                else if(tmp.status[j] == 1) late++;
                else if(tmp.status[j] == 2) leave++;
                else absence++;
            }
        }
        cout << "到课率:" << setprecision(2) << (double)(arrival/al) << endl;
        cout << "迟到率:" << setprecision(2) << (double)(late/al) << endl;
        cout << "请假率:" << setprecision(2) << (double)(leave/al) << endl;
        cout << "旷课率:" << setprecision(2) << (double)(absence/al) << endl;
    }
}classInfo;

void Init(){
    st[0] = "正常";
    st[1] = "迟到";
    st[2] = "请假";
    st[3] = "旷课";
    
}



int main()
{
    
    return	0;
}