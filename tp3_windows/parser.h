/*
 * parser.h
 *
 *  Created on: 6 jun. 2020
 *      Author: Nahu_
 */

#ifndef PARSER_H_
#define PARSER_H_

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param pFile FILE*
 * \param pArrayListEmployee LinkedList*
 * \param idSave int*
 * \return int (0 si sale todo ok.)(-1 si no sale todo ok)
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee,int* idSave);


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param pFile FILE*
 * \param pArrayListEmployee LinkedList*
 * \param idSaveBin int*
 * \return int (0 si sale todo ok.)(-1 si no sale todo ok)
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee,int* idSaveBin);

#endif /* PARSER_H_ */
