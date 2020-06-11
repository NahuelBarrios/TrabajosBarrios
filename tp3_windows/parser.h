/*
 * parser.h
 *
 *  Created on: 6 jun. 2020
 *      Author: Nahu_
 */

#ifndef PARSER_H_
#define PARSER_H_

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee,int* idSave);

int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee,int* idSaveBin);

#endif /* PARSER_H_ */
