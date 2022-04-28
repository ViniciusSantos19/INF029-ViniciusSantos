// valida matricula
int Validar_matricula(int val_matricula){
  if(val_matricula <= 0 && isalpha(val_matricula)){
    return 0;
  }
//valida sexo
  int Validar_sexo(char* vali_sexo){
  if(*vali_sexo != 'M' && *vali_sexo != 'F'){
   return ERRO_CADASTRO_SEXO; 
  }
}
int retorno = Validar_matricula(lista_professor[qnt_professor].matricula);
    if (retorno == 0){
        return ERRO_CADASTRO_MATRICULA;
    }
  int retorno1 = Validar_matricula(lista_alunos[qnt_alunos].matricula);
    if (retorno1 == 0){
        return ERRO_CADASTRO_MATRICULA;
    }
int Validar_data(int ano, int mes, int dia){
  int checar_ano = 0, checar_mes = 0;
  if(ano> 0 && ano <= 9999){
    checar_ano++;
  }
  if((dia>=1 && dia<=31) && (mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12)){
    checar_mes++;  
  }
  else if((dia>=1 && dia<=30) && (mes==4 || mes==6 || mes==9 || mes==11)){
    checar_mes++;  
  }
  else if(dia==29 && mes==2 && (ano%400==0 ||(ano%4==0 && ano%100!=0))){
    checar_mes++;  
  }
  if(checar_mes !=1 || checar_ano != 1){
    return 0;  
  }
  else{
    int aux = checar_mes + checar_ano;
    return aux;  
  }
}
/* int Validar_matricula(int val_matricula){
  if(val_matricula <= 0){
    return 0;
  }
  else
  return 1;
}
int Validar_semestre(int semestre){
   if(semestre <= 0 || semestre > 8){
    return 0;
   }
   else
   return 1;   
}
int Validar_data(int ano, int mes, int dia){
  int checar_ano = 0, checar_mes = 0;
  if(ano> 0 && ano <= 9999){
    checar_ano++;
  }
  if((dia>=1 && dia<=31) && (mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12)){
    checar_mes++;  
  }
  else if((dia>=1 && dia<=30) && (mes==4 || mes==6 || mes==9 || mes==11)){
    checar_mes++;  
  }
  else if(dia==29 && mes==2 && (ano%400==0 ||(ano%4==0 && ano%100!=0))){
    checar_mes++;  
  }
  if(checar_mes !=1 || checar_ano != 1){
    return 0;  
  }
  else{
    int aux = checar_mes + checar_ano;
    return aux;  
  }
}*/
for(i = 1; i < qnt_professor; i++){
    aux= lista_professor[i];
    j = i - 1;
    while(j >= 0 && ((aux.data_nascimento.ano < lista_professor[j-1].data_nascimento.ano)){
      lista_professor[j+1]=lista_professor[j];
      j = j - 1;
    }
    lista_professor[j+1] = aux;
  }