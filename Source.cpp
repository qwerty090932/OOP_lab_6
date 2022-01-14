// Предметная область - Больница
// Сампилов Мунко. подгруппа 4
#include <iostream>
#include <string>
using namespace std;
class human 
{
public:
	string name;
	string lastname;
	human (string name, string lastname) // конструктор
	{
		this-> name = name;
		this->lastname = lastname;
	}
	human(const human& other){ // конструктор копирования
		this->name = other.name;
		this->lastname = other.lastname;
	}
	human& operator = (const human& rhs) { // оператор присваивания
		this->name = rhs.name;
		this->lastname = rhs.lastname;

		return *this;
	}
};
class doctor : public human
{
private:
	string medical_specialties; // специальность
	string hospital; // место работы
public:
	string workmanship; // квалификация
	
	int countOfCurePatient; // кол-во вылеченных студентов
	doctor(string name, string lastname, string medical_specialties,string hospital) :human(name, lastname) { // конструктор
		this->name = name;
		this->lastname = lastname;
		this->medical_specialties = medical_specialties;
		this->workmanship = workmanship;
	}
	doctor(const doctor& other):human(name,lastname) { // конструктор копирования
		this->name = other.name;
		this->lastname = other.lastname;
		this->medical_specialties = other.medical_specialties;
		this->workmanship = workmanship;
	}
	doctor& operator = (const doctor& rhs) { // оператор присваивания
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
	void setWorkmanship(T _workmanship) { // шаблон для повышения квалификации или наоборот понижения
		workmanship = _workmanship;
	}
};
class patient : public human
{
private:
	string hospital; // поликлиника по месту жительства
public:
	string choiceDoctor; // выбор специалиста, к какому именно врачу хочет попасть пациент
	patient(string name, string lastname, string choiceDoctor, string hospital) :human(name, lastname) { // конструкторв
		this->choiceDoctor = choiceDoctor;
		this->name = name;
		this->lastname = lastname;
	}
	patient(const patient& other) :human(name, lastname) { // конструктор копирования
		this->choiceDoctor = other.choiceDoctor;
		this->name = other.name;
		this->lastname = other.lastname;
	}
	patient& operator = (const patient& rhs) { // оператор присваивания
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
	doctor doctor_1("Данил","Данилов","Окулист","2-ая поликлиника");
	doctor doctor_2("Николай", "Николаев", "Терапевт", "1-ая поликлиника");



	patient patient_1("Иван", "Иванов", "Окулист","2-ая поликлиника");
	patient patient_2("Кирилл", "Иванов", "Окулист", "2-ая поликлиника");
	patient patient_3("Евгений", "Волков", "Терапевт", "1-ая поликлиника");
	patient patient_4("Максим", "Кравцов", "Окулист", "2-ая поликлиника");
	patient patient_5("Михаил", "Михайлов", "Терапевт", "2-ая поликлиника");
	patient patient_6("Артём", "Борисов", "Окулист", "1-ая поликлиника");

	if ((doctor_1.getHospital() == patient_1.getHospital())&&(patient_1.getchoiceDoctor() == doctor_1.getMedical_specialties())) {
		cout << patient_1.name << " " << patient_1.lastname << " - " << "Здоров"<<endl;
		doctor_1.countOfCurePatient++;
	}
	else {
		cout << "Не тот врач или не та поликлиника";
	}
	if ((doctor_2.getHospital() == patient_2.getHospital()) && (patient_2.getchoiceDoctor() == doctor_2.getMedical_specialties())) {
		cout << patient_2.name << " " << patient_2.lastname << " - " << "Здоров"<<endl;
		doctor_2.countOfCurePatient++;
	}
	else {
		cout << "Не тот врач или не та поликлиника";
	}
	return 0;
}
