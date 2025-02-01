#include <bits/stdc++.h>
#include <vector>

using namespace std;


class Settings{
    protected:
        string RED(){
            return "\033[0;31m";
        }

        string GREEN(){
            return "\033[0;32m";
        }

        string YELLOW(){
            return "\033[0;33m";
        }

        string PURPLE(){
            return "\033[0;35m";
        }

        string CYAN(){
            return "\033[0;36m";
        }

        string WHITE(){
            return "\033[0;37m";
        }

        string BLUE(){
            return "\033[0;34m";
        }

        string BLACK(){
            return "\033[0;30m";
        }

        string DEFAULT(){
            return "\033[0m";
        }

};

class Internal_Resistances{
    private:
        vector<double> Vec;
    protected:
        vector<double> &getr_equivalent(){
            return Vec;
        }
        void setInternal_Resistances(unsigned int dim){
            double *temp = new double; unsigned int *NumberOfItems = new unsigned int;
            *NumberOfItems = dim;
            for(int i = 0; i < *NumberOfItems; i++)
            {
                cout << "r"<< i << ": ";
                cin >> *temp;
                getr_equivalent().push_back(*temp);
            }
            cout << "Your internal resistances are:\n";
            for(double el : getr_equivalent())
                cout << el << ' ';
            cout << '\n';
            delete(temp);
        }

};

class Electromotive_Voltages{
    private:
        vector<double> VecE;
    protected:
        vector<double> &getE_equivalent(){
            return VecE;
        }
        void setElectromotive_Voltages(unsigned int dim){
            double *temp = new double; unsigned int *NumberOfItems = new unsigned int;
            *NumberOfItems = dim;
            for(int i = 0; i < *NumberOfItems; i++)
            {
                cout << "E"<< i << ": ";
                cin >> *temp;
                getE_equivalent().push_back(*temp);
            }
            cout << "Your electromotive voltages are:\n";
            for(double el : getE_equivalent())
                cout << el << ' ';
            cout << '\n';
            delete(temp);
        }

};


class AutoCalc : protected Internal_Resistances, Electromotive_Voltages, Settings{
    private:
        double *E;
        double *E_equiv;
        double *r; 
        double *r_equiv;
        double *Ra;
        double *U;
        double *I;
        double *R;
        unsigned int *nE;
        unsigned int *nr;
        string *SettingOf_E;
        string *SettingOf_r;
    public:
        // Constructor
        AutoCalc(){
            E = new double;
            E_equiv = new double;
            r = new double; 
            r_equiv = new double;
            Ra = new double;
            U = new double;
            I = new double;
            R = new double;
            nE = new unsigned int;
            nr = new unsigned int;
            SettingOf_E = new string;
            SettingOf_r = new string;
        }

        //Constructor with arguments
        AutoCalc(double Val_E, double Val_r, double Val_Ra, double Val_U, double Val_I, unsigned int N_E, unsigned int N_r, string SettingOfE, string SettingOfr) {
            E = new double;
            r = new double; 
            Ra = new double;
            U = new double;
            I = new double;
            R = new double;
            nE = new unsigned int;
            nr = new unsigned int;
            SettingOf_E = new string;
            SettingOf_r = new string;

            setE(Val_E);
            setr(Val_r);
            setRa(Val_Ra);
            setU(Val_U);
            setI(Val_I);
            setnE(N_E);
            setnr(N_r);
            setSettingOf_E(SettingOfE);
            setSettingOf_r(SettingOfr);
            SolvingTheProblem();
        }

        //Copy constructor  
        AutoCalc(const AutoCalc& copy){
            E = new double(*copy.E);
            E_equiv = new double(*copy.E_equiv);
            r = new double(*copy.r);
            r_equiv = new double(*copy.r_equiv);
            Ra = new double(*copy.Ra);
            U = new double(*copy.U);
            I = new double(*copy.I);
            R = new double(*copy.R);
            nE = new unsigned int(*copy.nE);
            nr = new unsigned int(*copy.nr);
            SettingOf_E = new string(*copy.SettingOf_E);
            SettingOf_r = new string(*copy.SettingOf_r);
        }

        //Copying with the = operation
        AutoCalc &operator=(const AutoCalc& copy) {
            delete(E);
            delete(E_equiv);
            delete(r);
            delete(r_equiv);
            delete(Ra);
            delete(U);
            delete(I);
            delete(nE);
            delete(nr);
            delete(R);

            E = new double(*copy.E);
            E_equiv = new double(*copy.E_equiv);
            r = new double(*copy.r);
            r_equiv = new double(*copy.r_equiv);
            Ra = new double(*copy.Ra);
            U = new double(*copy.U);
            I = new double(*copy.I);
            R = new double(*copy.R);
            nE = new unsigned int(*copy.nE);
            nr = new unsigned int(*copy.nr);
            SettingOf_E = new string(*copy.SettingOf_E);
            SettingOf_r = new string(*copy.SettingOf_r);
            return *this;
        }

        // Deconstructor
        ~AutoCalc() {
            delete(E);
            delete(E_equiv);
            delete(r);
            delete(r_equiv);
            delete(Ra);
            delete(U);
            delete(I);
            delete(nE);
            delete(nr);
            delete(SettingOf_E);
            delete(SettingOf_r);
            delete(R);
        }

        //Setters zone
        void setE(double Val){*getAddressE() = Val;}
        void set_E_equiv(double Val){*getAddress_E_equiv() = Val;}
        void setr(double Val) {*getAddressr() = Val;}
        void set_r_equiv(double Val){*getAddress_r_equiv() = Val;}
        void setRa(double Val){*getAddressRa() = Val;}
        void setU(double Val){*getAddressU() = Val;}
        void setI(double Val){*getAddressI() = Val;}
        void setnE(unsigned int Val){*getAddressNumber_of_electromotive_voltages() = Val;}
        void setnr(unsigned int Val){*getAdressnr() = Val;}
        void setSettingOf_E(string Val){*getAddressSettingOf_E() = Val;}
        void setSettingOf_r(string Val){*getAdressSettingOf_r() = Val;}
        void setR(double Val){*getAddressR() = Val;}
        //Inherited from Internal_Resistances
        void setTheResistances(){setInternal_Resistances(getnr());}
        //Inherited from Electromotive_Voltages
        void setTheElecromotiveVoltages(){setElectromotive_Voltages(getnE());}
        //Inherited from Settings
        string Red(){return RED();}
        string Green(){return GREEN();}
        string Yellow(){return YELLOW();}
        string Purple(){return PURPLE();}
        string Cyan(){return CYAN();}
        string White(){return WHITE();}
        string Blue(){return BLUE();}
        string Black(){return BLACK();}
        string Default(){return DEFAULT();}

        //Getters for the address zone
        double *getAddressE(){return E;}
        double *getAddress_E_equiv(){return E_equiv;}
        double *getAddressr(){return r;}
        double *getAddress_r_equiv(){return r_equiv;}
        double *getAddressRa(){return Ra;}
        double *getAddressU(){return U;}
        double *getAddressI(){return I;}
        double *getAddressR(){return R;}
        unsigned int *getAddressNumber_of_electromotive_voltages(){return nE;}
        unsigned int *getAdressnr(){return nr;}
        string *getAddressSettingOf_E(){return SettingOf_E;}
        string *getAdressSettingOf_r(){return SettingOf_r;}

        //Getters for the values zone
        double getE(){return *E;}
        double get_E_equiv(){return *E_equiv;}
        double getr(){return *r;}
        double get_r_equiv(){return *r_equiv;}
        double getRa(){return *Ra;}
        double getU(){return *U;}
        double getI(){return *I;}
        double getR(){return *R;}
        unsigned int getnE(){return *nE;}
        unsigned int getnr(){return *nr;}
        string getSettingOf_E(){return *SettingOf_E;}
        string getSettingOf_r(){return *SettingOf_r;}
        //Inherited
        vector<double> &get__r_equivalent(){return getr_equivalent();}
        vector<double> &get__E_equivalent(){return getE_equivalent();}

        //Methods
            //Determination of the resistance R
        void get_R(){
            setR(getU() / getI());
        }

            //Determination of the equivalent internal resistance r
        void get_r_equivalent(){
            //If it's series
            if(getSettingOf_r() == "series"){
                double *sum = new double;
                for(double el : get__r_equivalent())
                    *sum += el;
                set_r_equiv(*sum);
                delete(sum);
            }
            //If it's parallel
            else if(getSettingOf_r() == "parallel"){
                    double *product = new double; double *sum = new double; *product = 1; *sum = 0;
                    double *temp_array0 = new double[getnr()]; double *temp_array1 = new double[getnr()];
                    unsigned int *index0 = new unsigned int; *index0 = 0;
                    for(double el : get__r_equivalent()){
                        *product *= el;
                        *(temp_array0 + *index0) = el;
                        *(temp_array1 + *index0) = el;
                        (*index0)++;
                    }
                    for(unsigned int i = 0; i < getnr(); ++i){
                        for(unsigned int j = i + 1; j < getnr(); ++j){
                            *sum += *(temp_array0 + i) * (*(temp_array1 + j));
                        }
                    }
                    set_r_equiv(*product/(*sum));
                    delete(temp_array0); delete(temp_array1); delete(sum); delete(product); delete(index0);
            }

        }

            //Determiantion of the equivalent electromotive voltage
        void get_E_equivalent(){
            //If it's series
            if(getSettingOf_E() == "series"){
                double *sum = new double;
                for(double el : get__E_equivalent())
                    *sum += el;
                set_E_equiv(*sum);
                delete(sum);
            }
            //If it's parallel
            else if(getSettingOf_E() == "parallel"){
                    double *sum = new double; *sum = 0;
                    vector<double>::iterator el0 = get__E_equivalent().begin(); 
                    vector<double>::iterator el1 = get__r_equivalent().begin(); 
                    while(el0 != get__E_equivalent().end() || el1 != get__r_equivalent().end()){
                        *sum += (*el0 / *el1);
                        el0++; el1++;
                    }
                    set_E_equiv(*sum * get_r_equiv());
                    delete(sum); 
            }

        }

        //Determination of the resistance of the ammeter RA
        void get_Ra(){
            setRa( ( get_E_equiv() - get_r_equiv() * getI() - getI() * getR() ) / getI() );
        }

        void get_U(unsigned int NumOfGen){
            double *Val = new double; *Val = 0; unsigned int *index = new unsigned int; *index = 0;
            vector<double>::iterator el0 = get__E_equivalent().begin(); 
            vector<double>::iterator el1 = get__r_equivalent().begin(); 
            while(el0 != get__E_equivalent().end() || el1 != get__r_equivalent().end()){
                if(NumOfGen == *index){
                    *Val = *el0 - getI() * (*el1);
                    break;
                }
                el0++; el1++; (*index)++;
            }
            setU(*Val);
            delete(Val); delete(index);
        }

        void SolvingTheProblem(){
            get_R(); get_r_equivalent(); get_E_equivalent(); get_Ra();
            cout << Yellow() << "Solving...\n" << Default();
            cout << "The value of the resistance is " << Red() << fixed << setprecision(2) << getR() << Default() << ".\n";
            cout << "The value of the resistance of the ammeter is " << Red() << fixed << setprecision(2) << getRa() << Default() << ".\n";
            cout << "The electromotive voltages are: "; 
            for(double el : get__E_equivalent())
                cout << Green() << el << Default() << ' ';
            cout << '\n';
            cout << "The internal resistances are: "; 
            for(double el : get__r_equivalent())
                cout << Green() << el << Default() << ' ';
            cout << '\n';
            cout << "The equivalent resistance is " << Red() << fixed << setprecision(2) << get_r_equiv() << Default() <<".\n";
            cout << "The equivalent electromotive tension is " << Red() << fixed << setprecision(2) << get_E_equiv() << Default() << ".\n";
            unsigned int *temp = new unsigned int;
            cout << Purple() << "On which generator (E0/E1/E2... ) do you want to move the voltmeter? (enter the number of E): " << Default();
            cin >> *temp;
            get_U(*temp);
            cout << "The voltage on the first generator is " << Red() << fixed << setprecision(2) << getU() << Default() << ".\n";
            delete(temp);
        }

};


int main(){
    //Variables area
    double *ValElectroVoltages = new double; double *ValIntResistances = new double; double *ValResOfAmmeter = new double; double *ValOfTension = new double; 
    double *ValOfElectricity = new double; unsigned int *NumElectroVoltages = new unsigned int; unsigned int *NumIntResistances = new unsigned int; 
    string *SettingOfElectroVoltages = new string; string *SettingOfIntResistances = new string; 

    AutoCalc *Obj1 = new AutoCalc;

    cout << "Let's kick things off! First, you need to enter the data:\n";
    cout << "The number of electromotive voltages: ";
    cin >> *NumElectroVoltages;
    Obj1 -> setnE(*NumElectroVoltages);
    Obj1 -> setTheElecromotiveVoltages();

    cout << "How the electromotive voltages are placed? (series / parallel): ";
    cin >> *SettingOfElectroVoltages;
    Obj1 -> setSettingOf_E(*SettingOfElectroVoltages);

    cout << "The number of internal resistance: ";
    cin >> *NumIntResistances;
    Obj1 -> setnr(*NumIntResistances);
    Obj1 -> setTheResistances();

    cout << "How the internal resistances are placed? (series / parallel): ";
    cin >> *SettingOfIntResistances;
    Obj1 -> setSettingOf_r(*SettingOfIntResistances);

    cout << "The value of the resistance of the ammeter: ";
    cin >> *ValResOfAmmeter;
    Obj1 -> setRa(*ValResOfAmmeter);

    cout << "The value of the tension : ";
    cin >> *ValOfTension;
    Obj1 -> setU(*ValOfTension);

    cout << "The value of the electricity: ";
    cin >> *ValOfElectricity;
    Obj1 -> setI(*ValOfElectricity);

    Obj1 -> SolvingTheProblem();
    delete(ValElectroVoltages); delete(ValIntResistances); delete(ValResOfAmmeter); delete(ValOfTension); delete(ValOfElectricity); delete(NumElectroVoltages); 
    delete(NumIntResistances); delete(SettingOfElectroVoltages); delete(SettingOfIntResistances); delete(Obj1);
    return 0;
}