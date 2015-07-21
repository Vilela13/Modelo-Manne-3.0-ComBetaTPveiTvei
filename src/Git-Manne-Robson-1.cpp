#include "Biblioteca.hpp"


int main(int argc, char **argv) {

	if( argc == 2){

		char *a;
		list<char*> ListaInstancias;
		string Nome;

		list<char*>::iterator it;

		ofstream ArquivoExcelResposta;

		int resolveu;

		int Status;
		double SolucaoPrimal;
		double SolucaoDual;
		double Gap;
		double Tempo;

	// -------------------------- Le arquivo com as instancias de Solomon e as guarda em uma lista ----------------------- //

		ifstream ArquivoInstanciaSaloman( "ArquivosSaloman.txt" );
		if(!ArquivoInstanciaSaloman){
			cout << " Arquivo nao Existe! \n FUDEU MUITO! \n";
		}else{

			ArquivoInstanciaSaloman >> Nome;
			cout << " \n   Arqmazena nome de instancias \n " << endl;
			while( Nome != "EOF"){
				a = new char[Nome.size()+1];
				a[Nome.size()]=0;
				memcpy(a,Nome.c_str(),Nome.size());
				cout << "  " << a  << endl ;
				ListaInstancias.push_back(a);
				ArquivoInstanciaSaloman >> Nome;
			}

			//cout << " Tamanho = " << ListaInstancias.size() << endl << endl;
		 }

		ArquivoInstanciaSaloman.close();

	// -------------------------- Le nome dos arquivos Solomon, carrega os dados, cria arquivo do R, Excel e cria arquivo que pode ser lido pelo Modelo ----------------------- //

		DadosSaloman *InstanciaSaloman = new DadosSaloman;

		while( ListaInstancias.size() > 0){
			it = ListaInstancias.begin();
			a = *it;
			ListaInstancias.pop_front();
			//cout <<  " ai 1" << endl;

			cout << a << endl;
			//cout <<  " ai 2" << endl;

			InstanciaSaloman->CarregarNumeroNosCoordenadas(a);
			//InstanciaSaloman->EscreverDadosLidosInstanciaSaloman();
			cout << " entrei 0 - carrega dados" << endl;

			InstanciaSaloman->CriarInstanciaSaloman(a);
			cout << " entrei 1 - escreve Instancia Salomon" << endl;

			InstanciaSaloman->EscreverComandosR(a,'4');
			// 1 => .ps	  2 =>.png   3 =>.jpeg    4 =>.pdf
			cout << " entrei 2 - escreve comandos R" << endl;

			InstanciaSaloman->EscreverComandosExcel(a);					// Não implementado ainda
			cout << " entrei 3 - escreve comandos excel" << endl;
		}
		free(InstanciaSaloman);


	// Resolve o problema
		No PreInstancia;

//Cria instância que criei na mão
		//PreInstancia.PreencheEstrutura();
		//PreInstancia.CriaTXT();


		char* Instancias;
		Instancias = argv[1];

		ifstream ArquivoInstancia;
		ArquivoInstancia.open(Instancias);
		if ( ArquivoInstancia.is_open() ){
			ArquivoInstancia >> Nome;
			while( Nome != "EOF"){
				a = new char[Nome.size()+1];
				a[Nome.size()]=0;
				memcpy(a,Nome.c_str(),Nome.size());
				//cout << a  << endl ;
				ListaInstancias.push_back(a);
				ArquivoInstancia >> Nome;
			}
			ArquivoInstancia.close();
		 // ----------- Cria uma Instancia para testes -------------------------- //
			//PreInstancia.PreencheEstrutura();
			//PreInstancia.CriaTXT();

		// ----------- Le um arquivo com as instancias a serem resolvidas pelo modelo, abre o arquivo com a instancia e o resolve -------------------------- //

			//cout << endl << endl << " Lendo arquivo " << endl << endl << endl;

			char Saida[200];
			int TamanhoEntrda;
			strcpy (Saida,"Res-");				// coloca Res- no char*
			TamanhoEntrda = strcspn (Instancias,".");	// Ve o tamanho do char* passado na entrada
			if(TamanhoEntrda > 12){				// Fixa o tamanho minimo da string
				TamanhoEntrda = 12;
			}
			strncat (Saida, Instancias, TamanhoEntrda);	// Cria o nome do arquivo de saida
			strcat (Saida,".txt");

			//cout << " Saida = > "<< Saida << "   Tamanho entrada = " << TamanhoEntrda << endl;

			ArquivoExcelResposta.open(Saida);

			ArquivoExcelResposta << " Instância" << '\t';
			ArquivoExcelResposta << " Status" << '\t';
			ArquivoExcelResposta << " Solução Primal" << '\t';
			ArquivoExcelResposta << " Solução Dual" << '\t';
			ArquivoExcelResposta << " Gap" << '\t';
			ArquivoExcelResposta << " Tempo" << '\n';

			No *Instancia;

			while( !ListaInstancias.empty()){
				Instancia = new No;
				it = ListaInstancias.begin();
				a = *it;
				ListaInstancias.pop_front();
				cout << " Modelo <= " << a << endl << endl;

				if( Instancia->LeDados(a) == 1){

					resolveu = Instancia->Cplex(a, Status, SolucaoPrimal, SolucaoDual, Gap, Tempo);
					cout << endl << endl << " Resolveu = " << resolveu << endl ;
					ArquivoExcelResposta << a  << '\t' ;
					switch (Status){
						case 0:	ArquivoExcelResposta <<  "Unknow" << '\t';						break;
						case 1:	ArquivoExcelResposta <<  "Feasible" << '\t';					break;
						case 2:	ArquivoExcelResposta <<  "Optimal" << '\t';						break;
						case 3:	ArquivoExcelResposta <<  "Infeasible" << '\t';					break;
						case 4:	ArquivoExcelResposta <<  "Unbounded" << '\t';					break;
						case 5: ArquivoExcelResposta <<  "Infeasible Or Unbounded" << '\t';		break;
						default:ArquivoExcelResposta <<  "Erro" << '\t';
					}
					ArquivoExcelResposta << " " <<   SolucaoPrimal << '\t' <<  " " << SolucaoDual << '\t' << " " <<   Gap << '\t' <<  " " << Tempo << '\n';

				}
				free(Instancia);
			}

			ArquivoExcelResposta.close();

			cout << "\n \n Galo Doido! \n \n";
			return 1;
		}else{
			cout << "\n \n Arquivo inexistente! \n \n";
			return 0;
		}

	}else{
		cout << "\n \n Passagem de parametros errada \n \n";
		return 0;
	}

}
