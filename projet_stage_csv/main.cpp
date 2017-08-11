#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <patientfactory.h>
#include <writer.h>

#include <csv.h>
using namespace std;

string file_name = "Korea-GGNgrowthSNUH_Loren.csv";

int main()
{
    vector<vector<string>> file_content = CSV::parse_from_file("res/" + file_name);
    file_content.erase(file_content.begin());//On enlève la permière ligne

    vector<Patient> patients;
    PatientFactory factory;
    for(vector<string> line : file_content)
    {
        Patient p = factory.create_from_strings(line);
        patients.push_back(p);
    }

    cout << patients[0].to_string() << endl;

    Writer saving_interesting_data;
    for (unsigned int i = 0; i < patients.size(); i++)
    {
        vector<CTScanAppointment> data = patients[i].get_appointments();
        string file_name = "./data_of_patients/"+std::to_string(i+1)+".dat";
        saving_interesting_data.writting(file_name,data);
    }

    return 0;
}
