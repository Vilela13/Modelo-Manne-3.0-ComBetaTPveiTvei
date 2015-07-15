/*
 * DadosSaloman.hpp
 *
 *  Created on: 19/05/2015
 *      Author: mvus
 */

#ifndef DADOSSALOMAN_HPP_
#define DADOSSALOMAN_HPP_

#include "Biblioteca.hpp"



class DadosSaloman{

public:
    DadosSaloman();

// Variaveis de leitura do arquivo

    //int X;					// Não sei para que serve mais
	string NomeInstancia;
	string Auxiliar;
	int NumeroVeiculos;
	int Capacidade;

	int NumeroNosDadosSaloman;

	vector< int > NumeroDoNo;
	vector< vector< int > > Coordenadas;
	vector< int > Demanda;
	vector< vector< int > > JanelaDeTempo;
	vector< int > TempoDeServico;
	int x;
	int y;
	int AuxiliarInt;

// Variaveis de escrita dos arquivos de saida

	int NumeroPlantas;
	vector < int > NoPlanta;
	int NumeroClientes;
	vector < int > NoCliente;
	int NumeroCaminhoes;
	int Velocidade;

// Declara variaveis

	char *b;
	char *aux1;
	string CaminhoArquivo1;
	string CaminhoArquivo2;
	string Nome;
	string NomeAux;
	string Versao;
	string Dados;
	string TXT;
	int NumeroVERSAO;

	int CaminhaoAux;

	vector < int > CaminhoesPlanta;
	vector < int > NumeroCarretas;		// guarda o numero de clientes

	double TempoDeDescarga;
	double TemproEntreEntregas;
	double TempoPlanta;
	double TempoEntreEntregas;

	vector < double > HoraInicioPlanta;
	vector < double > HoraFinalPlanta;

	vector < double > HoraInicioCliente;
	vector < double > HoraFinalCliente;


// Funções

	void CarregarNumeroNosCoordenadas( char*);

	void EscreverDadosLidosInstanciaSaloman();

	ifstream Instancia;

	void EscreverComandosR(char*,char );

	ofstream ComandosR;

	void EscreverComandosExcel(char*);

	ofstream ComandosExcel;

	void CriarInstanciaSaloman(char*);

	ofstream InstanciaSaloman;
	ofstream DadosInstanciaSalomonCriada;

    ~DadosSaloman();

};

DadosSaloman::DadosSaloman(){
	AuxiliarInt = 13131313;
	Capacidade  = 13131313;
	NumeroNosDadosSaloman = 13131313;
	NumeroVeiculos = 13131313;
	x = 13131313;
	y = 13131313;

}

void DadosSaloman::CarregarNumeroNosCoordenadas( char* a){

	int EscreveDadosLidos = 0;

	Instancia.open(a);

	Instancia >> NomeInstancia;

	if( EscreveDadosLidos == 1){
		cout << " Nome Instancia no carrega dados = " << NomeInstancia << endl;
	}

	for( int i = 0; i<3; i++){
        Instancia >>Auxiliar;
        if( EscreveDadosLidos == 1){
        	cout << Auxiliar << "  ";
        }
    }
	if( EscreveDadosLidos == 1){
		cout << endl;
	}

	Instancia >> NumeroVeiculos;
	if( EscreveDadosLidos == 1){
		cout << NumeroVeiculos ;
	}
	NumeroNosDadosSaloman = NumeroVeiculos;
	if( EscreveDadosLidos == 1){
		cout << "    (" << NumeroNosDadosSaloman << ")   ";
	}

	Instancia >> Capacidade;
	if( EscreveDadosLidos == 1){
		cout << Capacidade << endl;
	}

// Inicializa estrutura ds dados

	NumeroDoNo.resize( NumeroNosDadosSaloman + 1 );

	Coordenadas.resize( NumeroNosDadosSaloman + 1 );
    for( int i = 0; i <= NumeroNosDadosSaloman + 1; i++){
            Coordenadas[i].resize(2);

    }
    Demanda.resize( NumeroNosDadosSaloman + 1 );

    JanelaDeTempo.resize( NumeroNosDadosSaloman + 1 );
    for( int i = 0; i <= NumeroNosDadosSaloman + 1; i++){
    	JanelaDeTempo[i].resize(2);

	}
    TempoDeServico.resize( NumeroNosDadosSaloman + 1 );

// Guarda os dados a serem lidos

    for( int i = 0; i<12; i++){
        Instancia >>Auxiliar;
        if( EscreveDadosLidos == 1){
        	cout << Auxiliar << "\t";
        }
    }
    if( EscreveDadosLidos == 1){
    	cout << endl;
    }



    for( int i = 0; i <= NumeroNosDadosSaloman; i++){
        Instancia >> NumeroDoNo[i];

        Instancia >> Coordenadas[i][0];
        Instancia >> Coordenadas[i][1];

        Instancia >>Demanda[i];

        Instancia >> JanelaDeTempo[i][0];
        Instancia >> JanelaDeTempo[i][1];

        Instancia >>TempoDeServico[i];

        if( EscreveDadosLidos == 1){
            cout << NumeroDoNo[i] << "\t\t\t\t";
            cout << Coordenadas[i][0] << "\t";
            cout << Coordenadas[i][1] << "\t";
            cout << Demanda[i] << "\t\t";
            cout << JanelaDeTempo[i][0] << "\t";
            cout << JanelaDeTempo[i][1] << "\t\t\t";
            cout << TempoDeServico[i] << "\t\t" << endl;
        }


    }

    //cout << endl << endl << " DadosSaloman " << endl << endl;

    Instancia.close();


}

void DadosSaloman::EscreverDadosLidosInstanciaSaloman(){
	cout << endl << endl;

	cout << "Nome: " << NomeInstancia << endl;
	cout << "Numero de Veiculos: " << NumeroVeiculos<< endl;
	cout << "Capacidade: " << Capacidade << endl << endl;

	cout << " Numero No \t Coordenada X \t Coordenada Y \t Demanda \t InicioJanela \t FimJanela \t TempoServico"<< endl;
    for( int i = 0; i<=NumeroNosDadosSaloman; i++){
        cout << "\t " << NumeroDoNo[i] << "\t\t" << Coordenadas[i][0]  << "\t\t" << Coordenadas[i][1] << "\t\t" << Demanda[i] << "\t\t";
        cout << JanelaDeTempo[i][0]  << "\t\t" << JanelaDeTempo[i][1]  << "\t\t" << TempoDeServico[i] << endl;
    }

    cout << endl << endl;

}

void DadosSaloman::EscreverComandosR(char* a, char TipoArquivoSaida){

	int LimiteplotarX;
	int LimiteplotarY;

	LimiteplotarX = 45;
	LimiteplotarY = 90;

	double PosicaoTextoX;
	double PosicaoTextoY;
	int TamanhoLetraLegenda;

	PosicaoTextoX = 0.5;
	PosicaoTextoY = 2;
	TamanhoLetraLegenda = 2;

	char *b;
	string TipoComando;
	string NomeArquivoComandoR;
	TipoComando = "./ComR/CmdR-";


	if(!opendir ("ComR")){
		cout <<  "\n Nao tem diretorio \"ComR\"!!            FUDEU MUITO!! \n" << endl;

		if(system("mkdir ComR;") == 0){
			cout << " Criou pasta ComR" << endl;
		}else{
			cout << " Problema ao criar pasta ComR" << endl;
		}

		/* Outra maneira de criar arquivos

		SituacaoDiretorio = mkdir("./myfolder", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
		*/

		if(!opendir ("ComR")){
			cout << "\n Nao tem diretorio \"ComR\"!!             FUDEU MUITO!! \n" << endl;
		}else{
			cout << " Tem diretorio \"ComR\" !!  " << endl;
		}
	}else{
		cout << " Tem diretorio \"ComR\" !!  " << endl;
	}


		b = new char[TipoComando.size()+1];
		b[TipoComando.size()]=0;
		memcpy(b,TipoComando.c_str(),TipoComando.size());
		strcat(b,a);

		cout << endl <<  " Arquivo do comando R = " <<   b << endl << endl;

		ComandosR.open(b);

		ComandosR << "require(ggplot2) "<< endl;


		ComandosR << "Dados <- data.frame(nomes = c(" ;
		ComandosR << "\"N" << "0" << "\"";
		for( int c = 1; c <= NumeroClientes; c++){
			ComandosR << "," << "\"C" <<  c << "(" <<  NumeroCarretas[c] << ")"<<  "\"";
		}
		for( int p = 1; p <= NumeroPlantas; p++){
			ComandosR << ","<< "\"P" <<  p <<  "\"";
		}
		ComandosR << ")" << endl;

		//cout << " Aqui 1 " << endl;

		ComandosR << ", x <- c(" ;
		ComandosR << Coordenadas[0][0] ;
		for( int c = 1; c <= NumeroClientes; c++){
			ComandosR << ","<<  Coordenadas[	NoCliente[c] ][0] ;
		}
		for( int p = 1; p <= NumeroPlantas; p++){
			ComandosR << ","<<  Coordenadas[ NoPlanta[p] ][0] ;
		}
		ComandosR << ")" << endl;

		ComandosR << ", y <- c(" ;
		ComandosR << Coordenadas[0][1] ;
		for( int c = 1; c <= NumeroClientes; c++){
			ComandosR << ","<<  Coordenadas[	NoCliente[c] ][1] ;
		}
		for( int p = 1; p <= NumeroPlantas; p++){
			ComandosR << ","<<  Coordenadas[ NoPlanta[p] ][1] ;
		}
		ComandosR << ")" << endl;

		ComandosR << ", tipo <- c(" ;
		ComandosR << "3" ;
		for( int c = 1; c <= NumeroClientes; c++){
				ComandosR << ",6" ;
		}
		for( int p = 1; p <= NumeroPlantas; p++){
				ComandosR << ",4" ;
		}
		ComandosR << ")" << endl;

		ComandosR << ", tamanho <- c(" ;
		ComandosR << "1" ;
		for( int c = 1; c <= NumeroClientes; c++){
				ComandosR << ",1" ;
		}
		for( int p = 1; p <= NumeroPlantas; p++){
			ComandosR << ",2" ;
		}
		ComandosR << ")" << endl << ")"<< endl;


		if(!opendir ("Imagens")){
				cout <<  "\n Nao tem diretorio Imagens!!           FUDEU MUITO!! \n" << endl;

				if( system("mkdir Imagens;") == 0){
					cout << " Criou pasta Imagens " << endl;
				}else{
					cout << " Problema ao criar pasta Imagens " << endl;
				}
		}

		//NomeArquivoComandoR = "./Imagens/";
		NomeArquivoComandoR += a;

		NomeArquivoComandoR.resize( NomeArquivoComandoR.size() - 4 );



	// Cria Post Script
		if (TipoArquivoSaida == '1'){
			NomeArquivoComandoR += ".ps";

			ComandosR << "postscript('" << NomeArquivoComandoR << "')" << endl;
        }

    // Criar PNG
        if (TipoArquivoSaida == '2'){

			NomeArquivoComandoR += ".png";
			ComandosR << "png('" << NomeArquivoComandoR << "')" << endl;
        }

    // Criar Jpeg
		if (TipoArquivoSaida == '3'){

			NomeArquivoComandoR += ".jpg";
			ComandosR << "jpeg('" << NomeArquivoComandoR << "')" << endl;
        }

	 // Criar PDF
		if (TipoArquivoSaida == '4'){

			NomeArquivoComandoR += ".pdf";
			ComandosR << "pdf('" << NomeArquivoComandoR << "')" << endl;
        }

        ComandosR << "ggplot(Dados, aes(x,y)) + geom_point(aes(shape = factor(tipo),size =tamanho) ) + scale_size_continuous(range = c(3,4))";
        ComandosR << "+ scale_shape(solid = FALSE)+  geom_text(aes(label=nomes),";
        ComandosR << " hjust= " << PosicaoTextoX << ",vjust=" << PosicaoTextoY  ;
        ComandosR << " ,size = " << TamanhoLetraLegenda << ")";
        ComandosR << "+ xlim(0," << LimiteplotarX << ") + ylim(0," << LimiteplotarY << ")" << endl;
		ComandosR << "dev.off() ;" << endl;

		ComandosR.close();

		//cout << " Aqui 3" << endl;

}

void DadosSaloman::EscreverComandosExcel(char* a){

	/*
	char *b;
	string TipoComando;
	TipoComando = "CmdE-";

	b = new char[TipoComando.size()+1];
	b[TipoComando.size()]=0;
	memcpy(b,TipoComando.c_str(),TipoComando.size());
	strcat(b,a);

	FILE *fp;
	fp = fopen (b, "w");
	if (fp == NULL) {
		for( int i = 0; i <= NumeroNosDadosSaloman; i++){
			printf ("N %d \t %f \t %f \n",i,Coordenadas[i][0],Coordenadas[i][1]);
			fprintf (fp, "N %d \t %f \t %f \n",i,Coordenadas[i][0],Coordenadas[i][1]);
		}
	}
	fclose (fp);


	*/

	char *b;
	string TipoComando;
	TipoComando = "./ComE/CmdE-";




	if(!opendir ("ComE")){
		cout <<  "\n Nao tem diretorio \"ComE\"!!         FUDEU MUITO!! \n" << endl;

		if(system("mkdir ComE;") == 0){
			cout << " Criou pasta ComE" << endl;
		}else{
			cout << " Problema ao criar pasta ComE" << endl;
		}

		/* Outra maneira de criar arquivos

		SituacaoDiretorio = mkdir("./myfolder", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
		*/

		if(!opendir ("ComE")){
			cout << "\n Nao tem diretorio \"ComE\"!!        FUDEU MUITO!! \n" << endl;
		}else{
			cout << " Tem diretorio \"ComE\" !!  " << endl;
		}
	}else{
		cout << " Tem diretorio \"ComE\" !!  " << endl;
	}

	b = new char[TipoComando.size()+1];
	b[TipoComando.size()]=0;
	memcpy(b,TipoComando.c_str(),TipoComando.size());
	strcat(b,a);

	//cout << " galo => " << b << endl << endl;

	ComandosExcel.open(b);

	//cout << " Doido " << endl << endl;



    for( int i = 0; i <= NumeroNosDadosSaloman; i++){
        ComandosExcel << "N" <<  i  << "\t" << Coordenadas[i][0] << "\t" << Coordenadas[i][1] << endl ;
    }

    ComandosExcel.close();


}

void DadosSaloman::CriarInstanciaSaloman(char* a){


	NumeroVERSAO = 49;
	//NumeroVERSAO = 50;
	//NumeroVERSAO = 51;

	TempoDeDescarga = 0.1666667; // equivaelente a 10 minutos
	TemproEntreEntregas = 0.1666667; // equivaelente a 10 minutos
	TempoPlanta = 0.083333333; // equivalente a 5 minutos(4 min = 0.066667 ; 3min = 0.05 e 2min = 0.0333333)

	//binomial_distribution<int> distribution(5,0.5); 		// gera numeros segundo a distribuição binomial

// Cria diretorio caso não exista

	if(!opendir ("InstS")){
		cout <<  "\n\n Nao tem diretorio \"InstS\" !!        FUDEU MUITO!! \n" << endl;

		if(system("mkdir InstS;") == 0){
			cout << " Criou pasta InstS" << endl;
		}else{
			cout << " Problema ao criar pasta InstS" << endl;
		}

		/* Outra maneira de criar arquivos

		SituacaoDiretorio = mkdir("./myfolder", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
		*/

		if(!opendir ("InstS")){
			cout << "\n Nao tem diretorio  \"InstS\" !!        FUDEU MUITO!! \n" << endl;
		}else{
			cout << " Tem diretorio \"InstS\" !!  " << endl;
		}
	}else{
		cout << " Tem diretorio \"InstS\" !!  " << endl;
	}

// Cria o nome da instancia para o modelo

	Nome.assign(a);
	if( Nome.size() > 3){
		Nome.resize(Nome.size()-4);
		Versao = "-V";
		Versao += NumeroVERSAO;
		Nome.insert(Nome.size(),Versao);
		NomeAux = Nome;
		TXT = ".txt";
		Nome.insert(Nome.size(),TXT);

		cout << "      Nome da Instancia Solomon = " << Nome << endl << endl;

		a = new char[Nome.size()+1];
		a[Nome.size()]=0;
		memcpy(a,Nome.c_str(),Nome.size());

	}else{
		cout << "Arquivo passado com tamanho invaldo " <<  Nome << endl ;
	}

	//cout <<  "  Nome = " << Nome << endl;

	//CaminhoArquivo1 = "./";
	CaminhoArquivo1 = "./InstS/";

	b = new char[CaminhoArquivo1.size()+1];
	b[CaminhoArquivo1.size()]=0;
	memcpy(b,CaminhoArquivo1.c_str(),CaminhoArquivo1.size());
	strcat(b,a);

	cout << endl << "  Arquivo = " << a << "  Caminho = " << b << endl;

// Cria arquivo para guardar os dados da instancia criada

	InstanciaSaloman.open(b);

	if(!opendir ("Dat")){
		cout <<  "\n\n Nao tem diretorio \"Dat\" !!        FUDEU MUITO!! \n" << endl;

		if(system("mkdir Dat;") == 0){
			cout << " Criou pasta Dat" << endl;
		}else{
			cout << " Problema ao criar pasta Dat" << endl;
		}

		/* Outra maneira de criar arquivos

		SituacaoDiretorio = mkdir("./myfolder", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
		*/

		if(!opendir ("Dat")){
			cout << "\n Nao tem diretorio  \"Dat\" !!        FUDEU MUITO!! \n" << endl;
		}else{
			cout << " Tem diretorio \"Dat\" !!  " << endl;
		}
	}else{
		cout << " Tem diretorio \"Dat\" !!  " << endl;
	}

	CaminhoArquivo2 = "./Dat/";

	aux1 = new char[CaminhoArquivo2.size()+1];
	aux1[CaminhoArquivo2.size()]=0;
	memcpy(aux1,CaminhoArquivo2.c_str(),CaminhoArquivo2.size());
	strcat(aux1,a);
	DadosInstanciaSalomonCriada.open(aux1);

	cout << endl << "  Caminho salvar em pasta Dat = " << aux1 << endl;

	DadosInstanciaSalomonCriada << b << endl;
	InstanciaSaloman << NomeInstancia << endl;

	if(NomeInstancia[0] == 'R' && NomeInstancia[1] == 'C'){

//Inicializa Parametros

		NumeroPlantas 	= 1;

		//NumeroPlantas 	= 3;
		NoPlanta.resize(NumeroPlantas + 1);
		HoraInicioPlanta.resize(NumeroPlantas + 1);
		HoraFinalPlanta.resize(NumeroPlantas + 1);

		NoPlanta[1] = 4;	HoraInicioPlanta[1] = 7; 	HoraFinalPlanta[1] = 18;
		//NoPlanta[2] = 11;	HoraInicioPlanta[2] = 7; 	HoraFinalPlanta[2] = 18;
		//NoPlanta[3] = 19;	HoraInicioPlanta[3] = 7; 	HoraFinalPlanta[3] = 18;

		NumeroClientes 	= 9;
		NoCliente.resize(	NumeroClientes	+	1);
		HoraInicioCliente.resize(	NumeroClientes	+	1);
		HoraFinalCliente.resize( 	NumeroClientes	+	1);

/*
//dados com o gerador => NumeroVERSAO = 49;

		NoCliente[1] = 3;		HoraInicioCliente[1] = 8;	 HoraFinalCliente[1] = 8.5;		//3
		NoCliente[2] = 7;		HoraInicioCliente[2] = 8.5;	 HoraFinalCliente[2] = 9.5;		//5
		NoCliente[3] = 8;		HoraInicioCliente[3] = 8.5;	 HoraFinalCliente[3] = 10;		//4
		NoCliente[4] = 9;		HoraInicioCliente[4] = 9;	 HoraFinalCliente[4] = 10.5;		//2
		NoCliente[5] = 10;		HoraInicioCliente[5] = 9.5;	 HoraFinalCliente[5] = 11;		//4
		NoCliente[6] = 11;		HoraInicioCliente[6] = 10;	 HoraFinalCliente[6] = 11.5;		//1
		NoCliente[7] = 18;		HoraInicioCliente[7] = 10;	 HoraFinalCliente[7] = 12;		//1
		NoCliente[8] = 19;		HoraInicioCliente[8] = 10.5;	 HoraFinalCliente[8] = 12.5;		//2
		NoCliente[9] = 20;		HoraInicioCliente[9] = 11; 	 HoraFinalCliente[9] = 12.5;		//5


		NoCliente[10] = 2;		HoraInicioCliente[10] = 8;	 HoraFinalCliente[10] = 9;		//4
		NoCliente[11] = 5;		HoraInicioCliente[11] = 8.5;	 HoraFinalCliente[11] = 9;		//3
		NoCliente[12] = 6;		HoraInicioCliente[12] = 8.5; 	HoraFinalCliente[12] = 10;		//2
		NoCliente[13] = 14;		HoraInicioCliente[13] = 9;	 HoraFinalCliente[13] = 12;		//5
		NoCliente[14] = 15;		HoraInicioCliente[14] = 9.5;	 HoraFinalCliente[14] = 10;		//1
		NoCliente[15] = 16;		HoraInicioCliente[15] = 10.5;	 HoraFinalCliente[15] = 11;		//1
		NoCliente[16] = 17;		HoraInicioCliente[16] = 10.5;	 HoraFinalCliente[16] = 12;		//4

		NoCliente[17] = 12;		HoraInicioCliente[17] = 8;	 HoraFinalCliente[17] = 9;		//3
		NoCliente[18] = 21;		HoraInicioCliente[18] = 8;	 HoraFinalCliente[18] = 8.5;		//1
		NoCliente[19] = 22;		HoraInicioCliente[19] = 8.5; 	HoraFinalCliente[19] = 9.5;		//4
		NoCliente[20] = 23;		HoraInicioCliente[20] = 9.5;	 HoraFinalCliente[20] = 11;		//3
		NoCliente[21] = 24;		HoraInicioCliente[21] = 10;	 HoraFinalCliente[21] = 12;		//4
		NoCliente[22] = 25;		HoraInicioCliente[22] = 10.5;	 HoraFinalCliente[22] = 12.5;		//4
*/

//dados com o gerador => NumeroVERSAO = 50;

		NoCliente[1] = 3;		HoraInicioCliente[1] = 8;	 HoraFinalCliente[1] = 9;		//3
		NoCliente[2] = 6 ;		HoraInicioCliente[2] = 8;	 HoraFinalCliente[2] = 8.5;		//1
		NoCliente[3] = 7;		HoraInicioCliente[3] = 8.5;	 HoraFinalCliente[3] = 9;		//4
		NoCliente[4] = 8;		HoraInicioCliente[4] = 8.5;	 HoraFinalCliente[4] = 9;		//1
		NoCliente[5] = 9;		HoraInicioCliente[5] = 9;	 HoraFinalCliente[5] = 10.5;		//4
		NoCliente[6] = 10;		HoraInicioCliente[6] = 9.5;	 HoraFinalCliente[6] = 11;		//4
		NoCliente[7] = 13;		HoraInicioCliente[7] = 9.5;	 HoraFinalCliente[7] = 11.5;		//2
		NoCliente[8] = 18;		HoraInicioCliente[8] = 10.5;	 HoraFinalCliente[8] = 12;		//4
		NoCliente[9] = 20;		HoraInicioCliente[9] = 10.5; 	 HoraFinalCliente[9] = 12.5;		//5


		//NoCliente[10] = 1;		HoraInicioCliente[10] = 8;	 HoraFinalCliente[10] = 9;		//3
		//NoCliente[11] = 2;		HoraInicioCliente[11] = 8.5;	 HoraFinalCliente[11] = 9.5;		//4
		//NoCliente[12] = 5;		HoraInicioCliente[12] = 9; 	HoraFinalCliente[12] = 10.5;		//4
		//NoCliente[13] = 14;		HoraInicioCliente[13] = 9;	 HoraFinalCliente[13] = 10;		//1
		//NoCliente[14] = 15;		HoraInicioCliente[14] = 9.5;	 HoraFinalCliente[14] = 11;		//4
		//NoCliente[15] = 16;		HoraInicioCliente[15] = 10;	 HoraFinalCliente[15] = 11.5;		//5
		//NoCliente[16] = 17;		HoraInicioCliente[16] = 10.5;	 HoraFinalCliente[16] = 12;		//4

		//NoCliente[17] = 12;		HoraInicioCliente[17] = 8;	 HoraFinalCliente[17] = 9;		//4
		//NoCliente[18] = 21;		HoraInicioCliente[18] = 8;	 HoraFinalCliente[18] = 8.5;		//5
		//NoCliente[19] = 22;		HoraInicioCliente[19] = 8.5; 	HoraFinalCliente[19] = 9.5;		//3
		//NoCliente[20] = 23;		HoraInicioCliente[20] = 9.5;	 HoraFinalCliente[20] = 11;		//2
		//NoCliente[21] = 24;		HoraInicioCliente[21] = 10;	 HoraFinalCliente[21] = 12;		//2
		//NoCliente[22] = 25;		HoraInicioCliente[22] = 10.5;	 HoraFinalCliente[22] = 12.5;		//2

		NumeroCaminhoes = 10;

		//NumeroCaminhoes = 60;
		CaminhoesPlanta.resize(NumeroPlantas + 1);
		CaminhoesPlanta[1] = 10;
		//CaminhoesPlanta[2] = 10;
		//CaminhoesPlanta[3] = 10;

		Velocidade 		= 30;

		InstanciaSaloman << NumeroPlantas 	<< endl; 	// NUmero de plantas que serão nos Nós N4 ,N15 e o N22
		InstanciaSaloman << NumeroClientes 	<< endl;	// Numero de construções (clientes) , tirei o no N0 e dos 25 restantes eu tirei os 3 das plantas
		InstanciaSaloman << NumeroCaminhoes << endl;	// Coloquei 20 caminhões paracada planta (pode mudar depois.
		InstanciaSaloman << Velocidade 		<< endl;	// Velocidade dos caminhões

// Preenche o numero veiculos por planta

		CaminhaoAux = 1;
		for( int p = 1; p <= NumeroPlantas; p++){
			InstanciaSaloman << CaminhoesPlanta[p];
			for( int i = 1; i <= CaminhoesPlanta[p]; i++){
				InstanciaSaloman << " " << CaminhaoAux;
				CaminhaoAux++;
			}
			InstanciaSaloman << endl;
		}
		// InstanciaSaloman << " Veiculo planta " << endl;


// Preenche o numero de demandas por entrada

		srand(NumeroVERSAO);		// O gerador é o numero da versão
		NumeroCarretas.resize( NumeroClientes + 1 ); // vetor que guarda o numero de carretas por cliente

		for(int c =1; c <= NumeroClientes; c++){
				NumeroCarretas[c] = (rand()%5) + 1;
				//InstanciaSaloman << " No" << i << " ";
				InstanciaSaloman << NumeroCarretas[c] ;
				for( int i= 1; i <= NumeroCarretas[c] ; i++){
					InstanciaSaloman << " " << i;
				}
				InstanciaSaloman << endl;
		}

		// InstanciaSaloman <<  " Demanda entradas "<< endl;

		// ********** Escreve a distancia entre a planta e uma entrada *************
/*
		cout <<  " Distancia para o no 4" << endl;
		for(int i =1; i <= 25; i++){
			if( i != 4 && i != 15 && i != 22){
				cout << "4" << " -> " << i << "   " << sqrt( pow( Coordenadas[4][0] - Coordenadas[i][0],2) + pow( Coordenadas[4][1] - Coordenadas[i][1],2) ) / Velocidade << endl;
			}
		}
		cout << endl;

		cout <<  " Distancia para o no 15" << endl;
		for(int i =1; i <= 25; i++){
			if( i != 4 && i != 15 && i != 22){
				cout << "15" << " -> " << i << "   " << sqrt( pow( Coordenadas[15][0] - Coordenadas[i][0],2) + pow( Coordenadas[15][1] - Coordenadas[i][1],2) ) / Velocidade << endl;
			}
		}
		cout << endl;

		cout <<  " Distancia para o no 22" << endl;
		for(int i =1; i <= 25; i++){
			if( i != 4 && i != 15 && i != 22){
				cout << "22" << " -> " << i << "   " << sqrt( pow( Coordenadas[22][0] - Coordenadas[i][0],2) + pow( Coordenadas[22][1] - Coordenadas[i][1],2) ) / Velocidade << endl;
			}
		}
*/

// Preenche as localizações das plantas e entradas

		for(int p =1; p <= NumeroPlantas; p++){
			for(int i =1; i <= NumeroClientes; i++){
					InstanciaSaloman << sqrt( pow( Coordenadas[ NoPlanta[p] ][0] - Coordenadas[	NoCliente[i] ][0],2) + pow( Coordenadas[ NoPlanta[p] ][1] - Coordenadas[ NoCliente[i] ][1],2) ) / Velocidade << " ";
			}
			InstanciaSaloman << endl;
		}

		//InstanciaSaloman << " localidade plantas "<< endl;



// Preenche as localizações entradas e plantas
		for(int i =1; i <= NumeroClientes; i++){
			for(int p =1; p <= NumeroPlantas; p++){
				InstanciaSaloman << sqrt( pow( Coordenadas[ NoPlanta[p] ][0] - Coordenadas[ NoCliente[i] ][0],2) + pow( Coordenadas[  NoPlanta[p] ][1] - Coordenadas[ NoCliente[i] ][1],2) ) / Velocidade << " ";
			}
			InstanciaSaloman << endl;
		}

// Tempo descarga
		for( int v = 1; v <= NumeroCaminhoes; v++){
			InstanciaSaloman << v << endl;
			for( int c = 1; c <= NumeroClientes; c++){
				InstanciaSaloman << NumeroCarretas[c];
				for( int i = 1; i <= NumeroCarretas[c]; i++){
					InstanciaSaloman << " " << TempoDeDescarga;
				}
				InstanciaSaloman << endl;

			}
		}

// Tempo entre entregas
		for( int c = 1; c <= NumeroClientes; c++){
			InstanciaSaloman << TemproEntreEntregas << " ";
		}
		InstanciaSaloman << endl;

// Tempo de ir de uma entrada a outra
		CaminhaoAux = 1;
		for( int p = 1; p <= NumeroPlantas; p++){
			for( int v = 1; v <= CaminhoesPlanta[p]; v++){
				InstanciaSaloman << CaminhaoAux << endl;
				for(int i =1; i <= NumeroClientes; i++){
					for(int j =1; j <= NumeroClientes; j++){
						TempoEntreEntregas = 0;
						TempoEntreEntregas = sqrt( pow( Coordenadas[ NoCliente[i] ][0] - Coordenadas[ NoPlanta[p] ][0],2) + pow( Coordenadas[ NoCliente[i] ][1] - Coordenadas[ NoPlanta[p] ][1],2) ) / Velocidade;
						TempoEntreEntregas = TempoEntreEntregas + TempoPlanta ;
						TempoEntreEntregas = TempoEntreEntregas + sqrt( pow( Coordenadas[ NoCliente[j] ][0] - Coordenadas[ NoPlanta[p] ][0],2) + pow( Coordenadas[ NoCliente[j] ][1] - Coordenadas[ NoPlanta[p] ][1],2) ) / Velocidade;
						InstanciaSaloman << TempoEntreEntregas << " ";
					}
					InstanciaSaloman << endl;
				}
				CaminhaoAux++;
			}
		}
// Declara o intervalo estipulado pelos clientes
		for( int c = 1; c <= NumeroClientes; c++){
			InstanciaSaloman << HoraInicioCliente[c] << " ";
		}
		InstanciaSaloman << endl;

		for( int c = 1; c <= NumeroClientes; c++){
			InstanciaSaloman << HoraFinalCliente[c] << " ";
		}
		InstanciaSaloman << endl;

// Declara o intervalo estipulado pelos plantas
		for( int p = 1; p <= NumeroPlantas; p++){
			InstanciaSaloman <<  HoraInicioPlanta[p] << " ";
		}
		InstanciaSaloman << endl;

		for( int p = 1; p <= NumeroPlantas; p++){
			InstanciaSaloman <<  HoraFinalPlanta[p]  << " ";
		}
		InstanciaSaloman << endl;

// Armazena dados da instancia gerada
		DadosInstanciaSalomonCriada << " Gerador dos numeros aleatorios das demandas ( " << NumeroVERSAO << " ) " << endl;
		DadosInstanciaSalomonCriada << "Dados das plantas " << endl;
		for (int p = 1; p <= NumeroPlantas; p++){
			DadosInstanciaSalomonCriada <<  "   NoPlanta = " <<  NoPlanta[p];
			DadosInstanciaSalomonCriada << " Horario [ "	<< HoraInicioPlanta[p] << " - "	<< HoraFinalPlanta[p] << " ]" << endl;
		}
		DadosInstanciaSalomonCriada << "Dados dos Clientes " << endl;
		for( int c = 1; c <= NumeroClientes; c++){
			DadosInstanciaSalomonCriada << "  NoCliente = " << NoCliente[c];
			DadosInstanciaSalomonCriada << " \tDemanda em carretas ( " << NumeroCarretas[c] << " ) ";
			DadosInstanciaSalomonCriada << "Horario [ "	<< HoraInicioCliente[c] << " - " << HoraFinalCliente[c] << " ]" << endl;
		}

		DadosInstanciaSalomonCriada << endl << endl<< "Distancia das plantas para construcoes  em minutos" << endl << endl;
		for (int p = 1; p <= NumeroPlantas; p++){
			DadosInstanciaSalomonCriada <<  "   Planta = " <<  p << endl;
			DadosInstanciaSalomonCriada << "Construcao   Tempo de Ida    Tempo de Ida e Volta" << endl;
			for( int c = 1; c <= NumeroClientes; c++){
				DadosInstanciaSalomonCriada << c << "\t\t" << (sqrt( pow( Coordenadas[ NoPlanta[p] ][0] - Coordenadas[ NoCliente[c] ][0],2) + pow( Coordenadas[  NoPlanta[p] ][1] - Coordenadas[ NoCliente[c] ][1],2) ) / Velocidade)*60  << "\t\t";
				DadosInstanciaSalomonCriada << (sqrt( pow( Coordenadas[ NoPlanta[p] ][0] - Coordenadas[ NoCliente[c] ][0],2) + pow( Coordenadas[  NoPlanta[p] ][1] - Coordenadas[ NoCliente[c] ][1],2) ) / Velocidade)*60 + TempoPlanta * 60 + (sqrt( pow( Coordenadas[ NoPlanta[p] ][0] - Coordenadas[ NoCliente[c] ][0],2) + pow( Coordenadas[  NoPlanta[p] ][1] - Coordenadas[ NoCliente[c] ][1],2) ) / Velocidade)*60 << endl;
			}
		}

	}else{
		InstanciaSaloman << " Nao se enquadra! " << endl;
	}

/* Tempo de ir de uma entrada a outra */




	DadosInstanciaSalomonCriada.close();
	InstanciaSaloman.close();
}

DadosSaloman::~DadosSaloman(){
    for( int i = 0; i <= NumeroNosDadosSaloman; i++){
        Coordenadas[i].clear();
    }
    Coordenadas.clear();
}
#endif /* DADOSSALOMAN_HPP_ */