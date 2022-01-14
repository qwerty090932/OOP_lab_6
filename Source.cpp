#include <iostream>
#include <string>
using namespace std;
class human 
{
public:
	string name;
	string lastname;
	human (string name, string lastname) // пвапваппав
	{
		this-> name = name;
		this->lastname = lastname;
	}
	human(const human& other){ // êîíñòðóòîð êîïèðîâàíèÿ
		this->name = other.name;
		this->lastname = other.lastname;
	}
	human& operator = (const human& rhs) { // îïåðàòîð ïðèñâàèâàíèÿ
		this->name = rhs.name;
		this->lastname = rhs.lastname;

		return *this;
	}
};
class doctor : public human
{
private:
	string medical_specialties; // ñïåöèàëüíîñòü
	string hospital; // ìåñòî ðàáîòû
public:
	string workmanship; // êâàëèôèêàöèÿ 
	
	int countOfCurePatient; // êîë-âî âûëå÷åííûõ ïàöèåíòîâ
	doctor(string name, string lastname, string medical_specialties,string hospital) :human(name, lastname) { // êîíñòðóêòîð
		this->name = name;
		this->lastname = lastname;
		this->medical_specialties = medical_specialties;
		this->workmanship = workmanship;
	}
	doctor(const doctor& other):human(name,lastname) { // êîíñòðóòîð êîïèðîâàíèÿ
		this->name = other.name;
		this->lastname = other.lastname;
		this->medical_specialties = other.medical_specialties;
		this->workmanship = workmanship;
	}
	doctor& operator = (const doctor& rhs) { // îïåðàòîð ïðèñâàèâàíèÿ
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
	void setWorkmanship(T _workmanship) { // øàáëîí äëÿ ïîâûøåíèÿ êâàëèôèêàöèè èëè íàîáîðîò ïîíèæåíèÿ
		workmanship = _workmanship;
	}
};
class patient : public human
{
private:
	string hospital; // ïîëèêëèíèêà ïî ìåñòó æèòåëüñòâà
public:
	string choiceDoctor; // âûáîð ñïåöèàëèñòà, ê êàêîìó èìåííî âðà÷ó õî÷åò ïîïàñòü ïàöèåíò
	patient(string name, string lastname, string choiceDoctor, string hospital) :human(name, lastname) { // êîíñòðóêòîð
		this->choiceDoctor = choiceDoctor;
		this->name = name;
		this->lastname = lastname;
	}
	patient(const patient& other) :human(name, lastname) { // êîíñòðóòîð êîïèðîâàíèÿ
		this->choiceDoctor = other.choiceDoctor;
		this->name = other.name;
		this->lastname = other.lastname;
	}
	patient& operator = (const patient& rhs) { // îïåðàòîð ïðèñâàèâàíèÿ
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
	doctor doctor_1("Äàíèë","Äàíèëîâ","Îêóëèñò","2-àÿ ïîëèêëèíèêà");
	doctor doctor_2("Íèêîëàé", "Íèêîëàåâ", "Òåðàïåâò", "1-àÿ ïîëèêëèíèêà");



	patient patient_1("Èâàí", "Èâàíîâ", "Îêóëèñò","2-àÿ ïîëèêëèíèêà");
	patient patient_2("Êèðèëë", "Èâàíîâ", "Îêóëèñò", "2-àÿ ïîëèêëèíèêà");
	patient patient_3("Åâãåíèé", "Âîëêîâ", "Òåðàïåâò", "1-àÿ ïîëèêëèíèêà");
	patient patient_4("Ìàêñèì", "Êðàâöîâ", "Îêóëèñò", "2-àÿ ïîëèêëèíèêà");
	patient patient_5("Ìèõàèë", "Ìèõàéëîâ", "Òåðàïåâò", "2-àÿ ïîëèêëèíèêà");
	patient patient_6("Àðò¸ì", "Áîðèñîâ", "Îêóëèñò", "1-àÿ ïîëèêëèíèêà");

	if ((doctor_1.getHospital() == patient_1.getHospital())&&(patient_1.getchoiceDoctor() == doctor_1.getMedical_specialties())) {
		cout << patient_1.name << " " << patient_1.lastname << " - " << "Çäîðîâ"<<endl;
		doctor_1.countOfCurePatient++;
	}
	else {
		cout << "Íå òîò âðà÷ èëè íå òà ïîëèêëèíèêà";
	}
	if ((doctor_2.getHospital() == patient_2.getHospital()) && (patient_2.getchoiceDoctor() == doctor_2.getMedical_specialties())) {
		cout << patient_2.name << " " << patient_2.lastname << " - " << "Çäîðîâ"<<endl;
		doctor_2.countOfCurePatient++;
	}
	else {
		cout << "Íå òîò âðà÷ èëè íå òà ïîëèêëèíèêà";
	}
	return 0;
}
