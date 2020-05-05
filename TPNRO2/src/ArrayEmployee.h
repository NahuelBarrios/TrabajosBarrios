/*
 * employee.h
 *
 *  Created on: 4 may. 2020
 *      Author: Nahu_
 */

#ifndef ARRAYEMPLOYEE_H_
#define ARRAYEMPLOYEE_H_

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



/** \brief loads data typed by console
 *
 * \param list Employee*
 * \param len int
 * \param idCont int*
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int loadEmployee(Employee* list,int len,int* idCont);


/** \brief find empty returns if there is space to load data
 *
 * \param list Employee*
 * \param len int
 * \param position int*
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int findEmpty(Employee* list, int len, int* position);


/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \param position int*
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int findEmployeeById(Employee* list, int len,int id,int* position);



/** \brief modify the fields of the structure that the user wants
 *
 * \param list Employee*
 * \param len int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int modifyEmployee(Employee* list, int len);


/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
int removeEmployee(Employee* list, int len, int id);


/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [2] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Employee* list, int len, int order);

/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int printEmployees(Employee* list, int length);


/** \brief reports: order, list, average salary, total wages and how many wages exceed the average
 *
 * \param list Employee*
 * \param len int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int report(Employee* list ,int len);


/** \brief reports: order, list, the amount of wages and performs different operations that are requested
 *
 * \param list Employee*
 * \param len int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int salaryReport(Employee* list,int len);

#endif /* employee_H_ */
