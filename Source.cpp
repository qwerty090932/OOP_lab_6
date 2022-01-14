#include <iostream>
#include <string>
using namespace std;
class human 
{
public:
	string name;
	string lastname;
	human (string name, string lastname) // �����������
	{
		this-> name = name;
		this->lastname = lastname;
	}
	human(const human& other){ // ���������� �����������
		this->name = other.name;
		this->lastname = other.lastname;
	}
	human& operator = (const human& rhs) { // �������� ������������
		this->name = rhs.name;
		this->lastname = rhs.lastname;

		return *this;
	}
};
class doctor : public human
{
private:
	string medical_specialties; // �������������
	string hospital; // ����� ������
public:
	string workmanship; // ������������ 
	
	int countOfCurePatient; // ���-�� ���������� ���������
	doctor(string name, string lastname, string medical_specialties,string hospital) :human(name, lastname) { // �����������
		this->name = name;
		this->lastname = lastname;
		this->medical_specialties = medical_specialties;
		this->workmanship = workmanship;
	}
	doctor(const doctor& other):human(name,lastname) { // ���������� �����������
		this->name = other.name;
		this->lastname = other.lastname;
		this->medical_specialties = other.medical_specialties;
		this->workmanship = workmanship;
	}
	doctor& operator = (const doctor& rhs) { // �������� ������������
		this->name = rhs.name;
		this->lastname = rhs.lastname;
		this->medical_specialties = rhs.medical_specialties;
		return *this;
	}
	string getHospital() { 
		return hospital;
	}
	string getMedical_specialties() {
		return medical_specialties;
	}
	
	void setCountOfCurePatient(int count) {
		countOfCurePatient = count;
	}
	template <typename T>
	void setWorkmanship(T _workmanship) { // ������ ��� ��������� ������������ ��� �������� ���������
		workmanship = _workmanship;
	}
};
class patient : public human
{
private:
	string hospital; // ����������� �� ����� ����������
public:
	string choiceDoctor; // ����� �����������, � ������ ������ ����� ����� ������� �������
	patient(string name, string lastname, string choiceDoctor, string hospital) :human(name, lastname) { // �����������
		this->choiceDoctor = choiceDoctor;
		this->name = name;
		this->lastname = lastname;
	}
	patient(const patient& other) :human(name, lastname) { // ���������� �����������
		this->choiceDoctor = other.choiceDoctor;
		this->name = other.name;
		this->lastname = other.lastname;
	}
	patient& operator = (const patient& rhs) { // �������� ������������
		this->name = rhs.name;
		this->lastname = rhs.lastname;
		this->choiceDoctor = rhs.choiceDoctor;
		return *this;
	}
	string setchoiceDoctor(string _doctor) {
		choiceDoctor = _doctor;
	}
	string getchoiceDoctor() {
		return choiceDoctor;
	}
	string getHospital() {
		return hospital;
	}
};



int main() {
	setlocale(LC_ALL, "rus");
	doctor doctor_1("�����","�������","�������","2-�� �����������");
	doctor doctor_2("�������", "��������", "��������", "1-�� �����������");



	patient patient_1("����", "������", "�������","2-�� �����������");
	patient patient_2("������", "������", "�������", "2-�� �����������");
	patient patient_3("�������", "������", "��������", "1-�� �����������");
	patient patient_4("������", "�������", "�������", "2-�� �����������");
	patient patient_5("������", "��������", "��������", "2-�� �����������");
	patient patient_6("����", "�������", "�������", "1-�� �����������");

	if ((doctor_1.getHospital() == patient_1.getHospital())&&(patient_1.getchoiceDoctor() == doctor_1.getMedical_specialties())) {
		cout << patient_1.name << " " << patient_1.lastname << " - " << "������"<<endl;
		doctor_1.countOfCurePatient++;
	}
	else {
		cout << "�� ��� ���� ��� �� �� �����������";
	}
	if ((doctor_2.getHospital() == patient_2.getHospital()) && (patient_2.getchoiceDoctor() == doctor_2.getMedical_specialties())) {
		cout << patient_2.name << " " << patient_2.lastname << " - " << "������"<<endl;
		doctor_2.countOfCurePatient++;
	}
	else {
		cout << "�� ��� ���� ��� �� �� �����������";
	}
	return 0;
}