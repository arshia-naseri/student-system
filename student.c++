class Student
{
  public:
  
  String FirstName;
  String LastName;
  long ID;
  String gender;
  int age;
  int grade_class;
  bool isInternational;
  int number_of_subjects = 7;
  float grades[7]; //Array
  
  //Constructor
  Student(String FirstName, String LastName, long ID, String gender, int age, int grade_class, bool isInternational)
  {
    this->FirstName = FirstName;
    this->LastName = LastName;
    this->ID = ID;
    this->gender = gender;
    this->age = age; 
    this->grade_class = grade_class;
    this->isInternational = isInternational;
    // Grades
    this->grades[0] = 100; //math
    this->grades[1] = 49; //chem
    this->grades[2] = 35; //French
    this->grades[3] = 80; //English
    this->grades[4] = 75; //Physics
    this->grades[5] = 10; //Bio
    this->grades[6] = 60; //Geo
  }
  
  String subjectText(int index)
  {
    String subjects[] = {"math","chemistry","french","english","physics","biology","geology"};
    String sub = subjects[index];
    return sub;
  }
  
  void printStudentInfo()
  {
    Serial.println("Student details:");
  	Serial.println("> Student's first name is " + this->FirstName);
  	Serial.println("> Student's last name is " + this->LastName);
  	Serial.println("> Student's ID is " + String(this->ID));
  	Serial.println("> Student's gender is " + String(this->gender));
  	Serial.println("> Student's Age is " + String(this->age));
  	Serial.println("> Student's class grade is " + String(this->grade_class));
  	if(this->isInternational == true)
  	{
   		Serial.println("> The student is International"); 
  	}
  	else
  	{
   		Serial.println("> The student is Domestic"); 
  	}
  
  	Serial.println("--------------");
  }
  
  void printStudentReportCard()
  {
    Serial.println("Number of subjects: " + String(number_of_subjects));
    Serial.println("Student's report card:");
  	for(int i = 0; i < number_of_subjects; i++)
  	{
   	 Serial.println(this->subjectText(i)+" = "+ String(this->grades[i]));
  	}
  
  	Serial.println("--------------");
  }
  
  float calcAverage()
  {
   	float sum = 0;
    
    for(int i = 0; i < number_of_subjects; i++)
    {
      sum = sum + grades[i];
    }
    
    float avg = sum / number_of_subjects;
    
    return avg;
  }
  
  void printGradeAverage()
  {
   	Serial.println("The student's average is " + String( this->calcAverage() )); 
  }
  
  void retakeSubject()
  {
   	// Code Here
    for(int i = 0; i<number_of_subjects; i++)
    {
      if(this->grades[i] < 50)
      {
       Serial.println("Failed "+ this->subjectText(i) + " with grade of "+ String(this->grades[i]));
      }
    }
  }
};

void setup()
{
  Serial.begin(9600);
  //Student s1("Ash","Naseri",251127,"male", 24, 13, false);
  //Student s2("Sam", "K", 99999, "Female", 30, 13, true);
  
  Student s3("Alex", "R", 9999, "Unknown", 16, 10, false);
  
  s3.printStudentReportCard();
  
  s3.printGradeAverage();
  s3.retakeSubject();
}

void loop()
{
  
}
