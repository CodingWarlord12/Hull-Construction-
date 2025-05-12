#include <iostream> // THIS PROGRAM REPRESENTS A HYDROSTATICS PROGRAM THAT ARE GENERALLY USED IN MAKING THESE CALCULATIONS WITHIN MARITIME INDUSTRIES
using namespace std;

// Mathematical Functions used to calculate hull properties

double calculatewaterplanecoefficient(double lengthwaterline, double areaofhorizontalslice) { // The water plane coefficient equation calculates the fullness or fineness of the waterplane
	double Cw; // Declare double variable for Water Plane Coefficient

	Cw = areaofhorizontalslice / lengthwaterline;
	return Cw;
}
double calculateblockcoefficient(double shipdisplacement, double lengthwaterline, double shipbreadth, double shiptrim) { // Block coefficient measures the "fullness" of a ship or the ratio of the underwater volume of a ship to the volume of a rectangular block that has the same overall length, breadth, and draft.
	double Cb;

	Cb = shipdisplacement / (lengthwaterline * shipbreadth * shiptrim);
	return Cb;
}

double calculateprismaticcoefficient(double shipdisplacement, double areaofmidship, double lengthwaterline) { // Prismatic coefficient describes the fineness of the bow and stern without influence of midship fullness.
	double Cp;

	Cp = shipdisplacement / (areaofmidship * lengthwaterline);
	return Cp;
}

double calculatemidshipsectioncoefficient(double areamidship, double shipbreadth, double shiptrim) { // Midship Section Coefficient is the ratio of the actual area of the immersed portion of the ship's midship section to the product of the breadth and draught of the ship. A well-designed midship section is crucial for a ship's stability and safety.
	double Cm; 

	Cm = areamidship / (shipbreadth * shiptrim);
	return Cm;

}

int main() {

	cout << "This hydrostatics program takes key elements of the ship and calculates for 4 critical coefficients necessary" << endl;
	cout << "for a naval or marine engineer to know before pressing on to develop a hull prototype." << endl;
	cout << "An architect through his theoretical calculations for the Water Line Length, Ship Displacement, Ship Breadth, Ship trim, and the area of the midships." << endl;
	cout << "Through this essential data can he ensure proper calculations for the stability and purpose of his/her vessel." << endl;

	double waterline;
	double displacement;
	double horizontalarea;
	double breadth;
	double trim;
	double midshiparea;

	cout << "Please enter your calculation for your vessel's waterline: " << endl;
	cin >> waterline;
	cout << "Please enter the calculation for your vessel's displacement: " << endl;
	cin >> displacement;
	cout << "Please enter the calculation for your vessel's horizontal area: " << endl;
	cin >> horizontalarea;
	cout << "Please enter the calculation for your vessel's breadth: " << endl;
	cin >> breadth;
	cout << "Please enter the calculation for your vessel's trim: " << endl;
	cin >> trim;
	cout << "Finally, enter the calculation for your vessel's midship area: " << endl;
	cin >> midshiparea;

	try {

		double CW = calculatewaterplanecoefficient(waterline, horizontalarea);

		


		if ((CW < 0.67) || (CW > 0.92)) {
			throw runtime_error(" Waterplane coefficient is outside your desired proportions!");
		}
	
		if ((CW < 0.56) && (CW > 0.54) ) {
			cout << "Your vessel looks to be a bulk carrier or cruiser" << endl; 
		}

		if ((CW < 0.85) && (CW > 0.80)) {
			cout << "Your vessel looks to be a oil tanker" << endl;
		}
		if ((CW < 0.92) && (CW > 0.90)) {
			cout << "Your vessel looks to be a container ship" << endl;
		}
		else {
			cout << "Your vessel is of another design not listed in our charts" << endl;
		}

		
			cout << "Your vessel's water plane coefficient: " << CW << endl;


		double CB = calculateblockcoefficient(displacement, waterline, breadth, trim);
		
		if ((CB < 0.45) || (CB > 0.85)) {
			throw runtime_error(" Block coefficient is outside your desired proportions!");
		}
		else {
			cout << " Your vessel's water plane coefficient: " << CB << endl;
		}

		double CP = calculateprismaticcoefficient(displacement, midshiparea, waterline);

		if ((CP < 0.57) || (CB > 0.85)) {
			throw runtime_error(" Prismatic coefficient is outside your desired proportions!");
		}
		else {
			cout << " Your vessel's prismatic coefficient: " << CP << endl;
		}

		double CM = calculatemidshipsectioncoefficient(midshiparea, breadth, trim);
		

		if ((CM < 0.75) || (CB > 0.95)) {
			throw runtime_error("midship section coefficient is outside your desired proportions!");
		}
		else {
			cout << " Your vessel's midship section coefficient: " << CM << endl;
		}
	}

	catch (runtime_error excpt) {
		cout << "Error:" << excpt.what() << endl;
	}

	cout << "With the accepted dimensions provided by your calculations, your hull is approved for prototype construction and testing! Thank you for being the future for future maritime industries!" << endl;

	return 0;
}


	




