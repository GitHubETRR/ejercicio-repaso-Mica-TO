#include <stdio.h>
#define CantEMP 5

struct  empleado {
  unsigned char name[10];
  unsigned int age;
  unsigned int salary;
};

struct empleado datos_empleado();
char elegir_empleado();


int main(void) {
  char exit = 1;
  char option;
  struct empleado empleado [CantEMP];
  int max_sal = 0;
  char MSNum  = 0;
  int promedio = 0;
  char i = 0;
  while (exit){
    printf("1. Ingresar datos\n2. Procesar y mostrar información\n3. Salir\n");
    scanf("%d", &option);
    switch(option){
      case 1:
        printf("Ingresar datos\n");
        char emp = elegir_empleado();
        empleado[emp] = datos_empleado();
        if(empleado[emp].salary >= max_sal){
          max_sal = empleado[emp].salary;
          MSNum = emp;
        }
        break;
      case 2:
        /*printf("Procesar y mostrar información\n");
        for(i = 0; i<CantEMP; i++){
          printf("Empleado %d: ", i);
          printf("%s", empleado[i].name);
          printf("%d", empleado[i].age);
          printf("%d\n", empleado[i].salary);
        }*/
        for (i=0; i<CantEMP; i++){
          promedio = promedio + empleado[i].salary;
        }
        promedio/=CantEMP;
        printf("El empleado con mayor salario es %s con un salario de %d\nEl promedio de salarios es %d\n", 
        empleado[MSNum].name, max_sal, promedio);
        break;
      case 3:
      printf("Salir");
      exit = 0;
      break;
    }
  }
  return 0;
}

struct empleado datos_empleado(){
  struct empleado temp;
  printf("Ingrese el nombre del empleado: ");
  scanf("%s", temp.name);
  printf("Ingrese la edad del empleado: ");
  scanf("%d", &temp.age); 
  printf("Ingrese el salario del empleado: ");
  scanf("%d", &temp.salary);
  return temp;
}

char elegir_empleado(){
  char temp2;
  printf("ingrese el numero de empleado: ");
  scanf("%s", &temp2);
  printf("Empleado: %c\n", temp2);
  temp2--;
  return temp2;
}
