/*
 * employee.h
 *
 *  Created on: 4 may. 2020
 *      Author: Nahu_
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

typedef struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
}Employee;

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee* list, int len);


/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 *
*/
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);




int loadEmployee(Employee* list,int len,int* idCont);

int findEmpty(Employee* array, int size, int* posicion);

int findEmployeeById(Employee* list, int len,int id,int* posicion);

int modifyEmployee(Employee* array, int sizeArray);

int removeEmployee(Employee* list, int len, int id);

int sortEmployees(Employee* list, int len, int order);

#endif /* employee_H_ */
