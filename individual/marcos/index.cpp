//Marcos Vinicius Tavares Gomes

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Paciente{

    string CPF;
    string DtNascimento; 
    public:
    string Nome;
  
    Paciente(string _Nome, string _CPF, string _DtNascimento){
        this -> Nome=_Nome;
        this -> setCPF(_CPF);
        this -> setDtNascimento(_DtNascimento);
    }

    string getCPF(){
        return this -> CPF;
    }

    void setCPF(string _CPF){
        this->CPF = _CPF;
    }

    string getDtNascimento(){
        return this -> DtNascimento;
    }

    void setDtNascimento(string _DtNascimento){
    
        this -> DtNascimento = _DtNascimento;
    }

};

class Medico{
    string CRM;
    string Especialidade;

    public:
    string Nome;
   
    Medico(string _Nome, string _CRM, string _Especialidade){
        this -> Nome=_Nome;
        this -> setCRM(_CRM);
        this -> setEspecialidade(_Especialidade);
    }

    string getCRM(){
        return this -> CRM;
    }

    void setCRM(string _CRM){

        this->CRM = _CRM;
    }

    string getEspecialidade(){
        return this -> Especialidade;
    }

    void setEspecialidade(string _Especialidade){

        this -> Especialidade = _Especialidade;
    }

};

class Programa{
    public:
        vector<Paciente*> listaPacientes;
        vector<Medico*> listaMedicos;

    int localizaCPF(vector<Paciente*> pacientes, string CPF){
        int i=0;
                for(auto el : pacientes){
                    if(el->getCPF() == CPF){
                        return i;
                    }
                    i++;
                } return -1;
    };

    int localizaCRM(vector<Medico*> medicos, string CRM){
        int i=0;
                for(auto el : medicos){
                    if(el->getCRM() == CRM){
                        return i;
                    }
                    i++;
                } return -1;        
    };

    void moduloPaciente(){
        
        int opcao;

        do{
        cout << "Digite a opcao: " << endl;
        cout << "1. Incluir" << endl;
        cout << "2. Excluir" << endl;
        cout << "3. Alterar (CPF)" << endl;
        cout << "4. Listar" << endl;
        cout << "5. Localizar (CPF)" << endl;
        cout << "0. Sair" << endl;
        cin >> opcao;

        string auxNome, auxCPF, auxDtNascimento;
        if(opcao==1){
            bool condicao = 0;

            cout << "Digite o nome: ";
            getline(cin >> ws, auxNome);

            do{
                cout << "Digite o CPF (somente numeros): ";
                getline(cin >> ws, auxCPF);
                if(auxCPF.length()!=11){
                    condicao = 0;
                    cout << "ERRO, FORMA invalida!" << endl;
                }
                else{
                    int posicao = localizaCPF(listaPacientes, auxCPF);
                    if(posicao < 0){
                        condicao = 1;
                    }
                    else{
                    cout << "CPF ja cadastrado na lista" << endl;
                        condicao = 0;
                    }
                }
            }while(condicao == 0);
            

            cout << "Digite a data de nascimento: ";
            getline(cin >> ws, auxDtNascimento);

            Paciente *paciente = new Paciente(auxNome, auxCPF, auxDtNascimento);

            listaPacientes.push_back(paciente);
        }
        
        else
        if(opcao==2){
            cout << "Digite o CPF (numeros) do paciente que vai excluir: " << endl;
            getline(cin >> ws, auxCPF);

            int posicao = localizaCPF(listaPacientes, auxCPF);

            if(posicao < 0)
                cout << "Paciente nao encontrado" << endl;
                
            else{
                delete listaPacientes[posicao];
            listaPacientes.erase(listaPacientes.begin() + posicao);
            cout << "Paciente removido com sucesso." << endl;
            }        
        }

        else
        if(opcao==3){
            int alterar =0;

            cout << "Digite o CPF (somente numeros) do paciente que vai alterar: " << endl;
            getline(cin >> ws, auxCPF);

            int posicao = localizaCPF(listaPacientes, auxCPF);

            if(posicao < 0)
                cout << "Paciente nao encontrado" << endl;
                
            else{

                cout << "Estes sao os dados atuais do CPF mencionado: " << endl;
                cout << "Nome: " << listaPacientes.at(posicao)-> Nome << endl;
                cout << "Data de nascimento: " << listaPacientes.at(posicao)-> getDtNascimento() << endl;
                cout << "Deseja alterar o nome, data de nascimento ou os dois?" << endl;
                cout << "1. Modificar nome" << endl;
                cout << "2. Modificar data de nascimento" << endl;
                cout << "3. Modificar ambos" << endl;
                cout << "0. Retornar para o menu principal" << endl;
                cin >> alterar;
                
                if(alterar==1){
                    
                    cout << "Digite o novo nome: ";
                    getline(cin >> ws, listaPacientes.at(posicao) -> Nome);

                }else
                if(alterar==2){
            
                    cout << "Digite a nova data de nascimento: ";
                    getline(cin >> ws, auxDtNascimento);
                    listaPacientes.at(posicao) -> setDtNascimento(auxDtNascimento);

                }else
                if(alterar==3){

                    cout << "Digite o novo nome: ";
                    getline(cin >> ws, listaPacientes.at(posicao) -> Nome);  
                    cout << "Digite a nova data de nascimento: ";
                    getline(cin >> ws, auxDtNascimento);
                    listaPacientes.at(posicao) -> setDtNascimento(auxDtNascimento);

                }else

                if(alterar==0){

                }else{

                    cout << "Opcao nao valida!" << endl;

                }
            }
        }

        else
        if(opcao==4){
            for(auto el : listaPacientes){
                cout << el -> Nome << endl;
                cout << el -> getCPF() << endl;
                cout << el -> getDtNascimento() << endl;
                cout << endl;
            }
        }

        else
        if(opcao==5){
            cout << "Digite o CPF (numeros) do paciente que vai localizar: ";
            getline(cin >> ws, auxCPF);

            int posicao = localizaCPF(listaPacientes, auxCPF);

            if(posicao <0)
                cout << "Paciente nao encontrado" << endl;
                
            else{
                    cout << listaPacientes.at(posicao)-> Nome << endl;
                    cout << listaPacientes.at(posicao)-> getDtNascimento() << endl;
            }

        }
        else
        if(opcao==0){
        }
        else{
            cout << "Opcao  nao valida!";
        }
        }while(opcao != 0);
    };

    void moduloMedico(){
        int opcao;

        do{
        cout << "Digite a opcao: " << endl;
        cout << "1. Incluir" << endl;
        cout << "2. Excluir" << endl;
        cout << "3. Alterar (somente por CRM)" << endl;
        cout << "4. Listar" << endl;
        cout << "5. Localizar (CRM)" << endl;
        cout << "0. Sair" << endl;
        cin >> opcao;

        string auxNome, auxCRM, auxEspecialidade; 
        if(opcao==1){
            bool condicao = 0;
            cout << "Digite o nome: ";
            getline(cin >> ws, auxNome);

            do{
                cout << "Digite o CRM: ";
                getline(cin >> ws, auxCRM);
                int posicao = localizaCRM(listaMedicos, auxCRM);
                        if(posicao < 0){
                            condicao = 1;
                        }
                        else{
                        cout << "CRM ja esta na lista de medicos!" << endl;
                            condicao = 0;
                        }
            }while(condicao==0);

            cout << "Digite a area do especialista: ";
            getline(cin >> ws, auxEspecialidade);

            Medico *medico = new Medico(auxNome, auxCRM, auxEspecialidade);

            listaMedicos.push_back(medico);
        }
        
        else
        if(opcao==2){
            cout << "Digite o CRM do medico que deseja excluir: " << endl;
            getline(cin >> ws, auxCRM);

            int posicao = localizaCRM(listaMedicos, auxCRM);

            if(posicao < 0)
                cout << "Medico nao localizado" << endl;
                
            else{
                delete listaMedicos[posicao];
            listaMedicos.erase(listaMedicos.begin() + posicao);
            cout << "Medico excluido com sucesso!" << endl;
            }        
        }

        else
        if(opcao==3){
            int alterar =0;

            cout << "Digite o CRM do medico que deseja alterar: " << endl;
            getline(cin >> ws, auxCRM);

            int posicao = localizaCRM(listaMedicos, auxCRM);

            if(posicao < 0)
                cout << "Medico nao encontrado" << endl;
                
            else{

                cout << "Estes sao os dados atuais do CRM citado: " << endl;
                cout << "Nome: " << listaMedicos.at(posicao)-> Nome << endl;
                cout << "Especialidade: " << listaMedicos.at(posicao)-> getEspecialidade() << endl;
                cout << "Deseja alterar o nome, especialidade ou os dois?" << endl;
                cout << "1. Alterar nome" << endl;
                cout << "2. Alterar especialidade" << endl;
                cout << "3. Alterar ambos" << endl;
                cout << "0. Voltar para o menu principal" << endl;
                cin >> alterar;
                
                if(alterar==1){
                    
                    cout << "Digite o novo nome: ";
                    getline(cin >> ws, listaMedicos.at(posicao) -> Nome);

                }else
                if(alterar==2){
            
                    cout << "Digite a nova especialidade: ";
                    getline(cin >> ws, auxEspecialidade);
                    listaMedicos.at(posicao) -> setEspecialidade(auxEspecialidade);

                }else
                if(alterar==3){

                    cout << "Digite o novo nome: ";
                    getline(cin >> ws, listaMedicos.at(posicao) -> Nome);  
                    cout << "Digite a nova especialidade: ";
                    getline(cin >> ws, auxEspecialidade);
                    listaMedicos.at(posicao) -> setEspecialidade(auxEspecialidade);

                }else

                if(alterar==0){

                }else{

                    cout << "Opcao nao valida!" << endl;

                }
            }

        }

        else
        if(opcao==4){
            for(auto el : listaMedicos){
               cout << el -> Nome << endl;
                cout << el -> getCRM() << endl;
                cout << el -> getEspecialidade() << endl;
                cout << endl;
            }
        }

        else
        if(opcao==5){
            cout << "Digite o CRM do medico que deseja alterar: ";
            getline(cin >> ws, auxCRM);

            int posicao = localizaCRM(listaMedicos, auxCRM);

            if(posicao <0)
                cout << "Medico não encontrado" << endl;
                
            else{
                    cout << listaMedicos.at(posicao)-> Nome << endl;
                    cout << listaMedicos.at(posicao)-> getEspecialidade() << endl;
            }
        }
        else
        if(opcao==0){
        }
        else{
            cout << "Opcao  nao valida!";
        }
        }while(opcao != 0);
    };
        
};


int main(){
    int modulo;
    Programa ClinicaMedicaSemDodoi;
    
do{
    cout << "###### CLINICA MEDICA SEM DODOI LTDA. ######" << endl;
    cout << "Acesso no modulo de Pacientes ou de Medicos?" << endl;
    cout << "1. Pacientes" << endl;
    cout << "2. Medicos" << endl;
    cout << "0. Encerrar programa" << endl;
    cin >> modulo;

if(modulo==1){
    ClinicaMedicaSemDodoi.moduloPaciente();
}

else if(modulo==2){
    ClinicaMedicaSemDodoi.moduloMedico();
}

else if(modulo==0){
    cout << "Programa encerrado!";
}
else{
    cout << "Entrada nao valida." << endl;
}
}while(modulo!=0);
    return 0;
}