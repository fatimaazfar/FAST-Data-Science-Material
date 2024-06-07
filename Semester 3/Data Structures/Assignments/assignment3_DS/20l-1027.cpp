#include <iostream>
using namespace std;
class PatientRecord {
	int patient_id;
	string patient_name;
	string admission_date;
	string disease_diagnose;
	bool status;
public:
	friend class HospitalData;
	PatientRecord() {
		patient_id = 0;
		patient_name = "";
		admission_date = "";
		disease_diagnose = "";
		status = false;
	}

	PatientRecord(int id, string name, string date, string disease, bool s) {
		patient_id = id;
		patient_name = name;
		admission_date = date;
		disease_diagnose = disease;
		status = s;
	}
	PatientRecord(const PatientRecord& patient) {
		patient_id = patient.patient_id;
		patient_name = patient.patient_name;
		admission_date = patient.admission_date;
		disease_diagnose = patient.disease_diagnose;
		status = patient.status;
	}

	PatientRecord operator=(const PatientRecord& patient) {
		patient_id = patient.patient_id;
		patient_name = patient.patient_name;
		admission_date = patient.admission_date;
		disease_diagnose = patient.disease_diagnose;
		status = patient.status;

		return *this;
	}

	void Print() {
		cout << "Patient ID: " << patient_id << endl;
		cout << "Name: " << patient_name << endl;
		cout << "Admission Date: " << admission_date << endl;
		cout << "Disease Diagnosis: " << disease_diagnose << endl;
		cout << "Status: ";
		if (status)
			cout << "Admitted" << endl;
		else
			cout << "Discharged" << endl;
	}
	int get_patientID() const { return patient_id; }
	string get_patientName() const { return patient_name; }
	string get_admissionDate() const { return admission_date; }
	string get_diseaseDiagnose() const { return disease_diagnose; }
	bool get_patientStatus() const { return status; }
	void set_patientID(int id) { patient_id = id; }
	void set_patientName(string name) { patient_name = name; }
	void set_admissionDate(string date) { admission_date = date; }
	void set_diseaseDiagnose(string diagnose) { disease_diagnose = diagnose; }
	void set_patientStatus(bool s) { status = s; }
};

class TNode {
	PatientRecord record;
	TNode* leftChild;
	TNode* rightChild;
public:
	TNode() {
		PatientRecord record;
		leftChild = nullptr;
		rightChild = nullptr;
	}
	TNode(PatientRecord data, TNode* leftChild, TNode* rightChild) {
		record = data;
		leftChild = leftChild;
		rightChild = rightChild;
	}
	friend class HospitalData;
};

class HospitalData {
	TNode* root;
	int size;

	void rightRotation(TNode*& temp) {
		TNode* orphan = temp->leftChild->rightChild;
		TNode* y = temp->leftChild;

		y->rightChild = temp;
		temp->leftChild = orphan;

		temp = y;
	}
	void leftRotation(TNode*& temp) {
		TNode* orphan = temp->rightChild->leftChild;
		TNode* y = temp->rightChild;

		y->leftChild = temp;
		temp->rightChild = orphan;

		temp = y;
	}
	//Insert function inserts a record into the tree and moves it to the root.
	void Insert(TNode*& ptr, PatientRecord record) {
		if (!ptr)
			ptr = new TNode(record, nullptr, nullptr);
		else if (ptr->record.patient_id < record.patient_id) {
			Insert(ptr->rightChild, record);
			leftRotation(ptr);
			size++;
		}
		else {
			Insert(ptr->leftChild, record);
			rightRotation(ptr);
			size++;
		}
	}
	//This func prints the patients who are currently admitted to the hospital.
	void PrintAdmitted(TNode* ptr) {
		if (ptr) {
			if (ptr->record.status) {
				ptr->record.Print();
				cout << endl;
			}
			PrintAdmitted(ptr->leftChild);
			PrintAdmitted(ptr->rightChild);
		}
	}
	void Print(TNode* ptr) {
		if (ptr)
		{
			Print(ptr->leftChild);
			ptr->record.Print();
			Print(ptr->rightChild);
		}
	}
	//This func deletes a given node by copying it's predcessor to it's place.
	bool Remove(TNode*& ptr, int const id) {
		if (!ptr)
			return false;
		if (ptr->record.patient_id > id)
			Remove(ptr->leftChild, id);
		else if (ptr->record.patient_id < id)
			Remove(ptr->rightChild, id);
		else if (ptr->leftChild != nullptr && ptr->rightChild != nullptr) {
			ptr->record = find_max(ptr->rightChild)->record;
			Remove(ptr->rightChild, ptr->record.patient_id);
		}
		else {
			TNode* temp = ptr;
			if (ptr->rightChild)
				ptr = ptr->rightChild;

			else
				ptr = ptr->leftChild;
			delete temp;
			temp = nullptr;
			return true;
		}
	}
	//this func finds the next predecessor of a given node.
	TNode* find_max(TNode* ptr) {
		while (ptr->rightChild)
			ptr = ptr->rightChild;
		return ptr;
	}
	// deletes the whole tree
	void Destroy(TNode* ptr) {
		if (ptr) {
			Destroy(ptr->leftChild);
			Destroy(ptr->rightChild);
			delete ptr;
		}
	}

	//Search function to find a patient of given id and move it to the desired level.
	void Search(PatientRecord& record, TNode* &ptr, int level, int currlevel, int id, bool& flag) {
		if (ptr == nullptr)
			return;
		else if (ptr->record.patient_id == id) {
			flag = true;
			record = ptr->record;
			return;
		}
		else if (ptr->record.patient_id > id) {
			Search(record, ptr->leftChild, level, currlevel + 1, id, flag);
			if (flag) {
				if (currlevel >= level)
					rightRotation(ptr);
				flag = true;
				return;
			}
			else {
				flag = false;
				return;
			}
		}
		else {
			Search(record, ptr->rightChild, level, currlevel + 1, id, flag);
			if (flag) {
				if (currlevel >= level)
					leftRotation(ptr);
				flag = true;
				return;
			}
			else {
				flag = false;
				return;
			}
		}
	}
	void returnID(TNode* ptr, int& curr, int median_index, int& desired_id)
	{
		if (ptr)
		{
			returnID(ptr->leftChild, curr, median_index, desired_id);
			curr++;
			if (curr == median_index) //recurses till current and the max median index are not equal.
			{
				desired_id = ptr->record.patient_id;
				return;
			}
			returnID(ptr->rightChild, curr, median_index, desired_id);
		}
	}
public:
	HospitalData() : root(nullptr), size(0) {} // Default Constructor
	~HospitalData() { // Destructor
		Destroy(root);
		root = nullptr;
		size = 0;
	}
	void Insert(PatientRecord record) //wrapper function for Insert.
	{ 
		Insert(root, record);
	} 
	void Print() // wrapper function for Print.
	{ 
		Print(root); 
	} 
	void PrintAdmitted() //wrapper function for PrintAdmitted.
	{ 
		PrintAdmitted(root);
	} 
	void Remove(int const id)  //wrapper function for remove.
	{ 
		if (Remove(root, id)) size--; 
	}
	bool Search(PatientRecord record, int level, int id) //wrapper function for search.
	{ 
		bool flag = false;
		Search(record, root, level, 0, id, flag);
		return flag;
	}
	void Split(HospitalData& ptr) //this function splits the tree from its median into two separate trees
	{
		int median = size / 2;
		int medianid = -999;
		int initial = 0;
		returnID(root, initial, median, medianid);
		PatientRecord temp = root->record;
		Search(temp, 0, medianid);
		if (root && root->rightChild)
			ptr.root = root->leftChild;
	}
};

int main() {
	HospitalData H;
	H.Insert(PatientRecord(1, "fatima1", "13-7-2021", "flu", true));
	H.Insert(PatientRecord(2, "fatima2", "17-7-2021", "corona", true));
	H.Insert(PatientRecord(3, "fatima3", "20-2-2021", "cough", false));
	H.Insert(PatientRecord(4, "fatima4", "25-3-2021", "cancer", false));
	H.Insert(PatientRecord(5, "fatima5", "2-4-2021", "abc", true));
	H.Insert(PatientRecord(10, "fatima6", "12-5-2021", "def", true));
	H.Insert(PatientRecord(6, "fatima7", "22-6-2021", "ghi", true));
	H.Insert(PatientRecord(7, "fatima8", "30-11-2021", "jkl", true));

	H.Print();

	cout << endl << endl;

	PatientRecord P1(4, "fatima4", "25-3-2021", "cancer", false);
	H.Remove(10);
	if (H.Search(P1, 0, 1))
		cout << "Found." << endl;
	else
		cout << "Not found." << endl;
	H.PrintAdmitted();
	HospitalData* H2 = new HospitalData();

	H.Split(*H2);

	cout << endl << endl;

	H2->Print();

	system("pause");
	return 0;
}