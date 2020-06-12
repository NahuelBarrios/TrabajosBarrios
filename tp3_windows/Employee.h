#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

//****************************************************************************************
/** \brief Crea un nuevo empleado, pide espacio en memoria e inicializa en 0 los campos.
 *
 * \return empleado (Puntero a estructura Employee*)
 */
Employee* employee_new();


/** \brief Crea(Carga) un empleado a traves de los parametros que recibe.
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param horasTrabajadasStr char*
 * \param sueldo char*
 * \return empleado (Puntero a estructura Employee*)
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo);


/** \brief Elimina un empleado
 *
 * \param this Employee*
 * \return int (0 si sale todo ok.)(-1 si no sale todo ok)
 */
int employee_delete(Employee* this);


/** \brief Carga un Id al campo id.
 *
 * \param this Employee*
 * \param id int*
 * \return int (0 si sale todo ok.)(-1 si no sale todo ok)
 *
 */
int employee_setId(Employee* this,int id);


/** \brief Obtiene un Id del campo id.
 *
 * \param this Employee*
 * \param id int*
 * \return int (0 si sale todo ok.)(-1 si no sale todo ok)
 *
 */
int employee_getId(Employee* this,int* id);


/** \brief Carga un Nombre al campo nombre.
 *
 * \param this Employee*
 * \param nombre char*
 * \return int (0 si sale todo ok.)(-1 si no sale todo ok)
 *
 */
int employee_setNombre(Employee* this,char* nombre);


/** \brief Obtiene un Nombre del campo nombre.
 *
 * \param this Employee*
 * \param nombre char*
 * \return int (0 si sale todo ok.)(-1 si no sale todo ok)
 *
 */
int employee_getNombre(Employee* this,char* nombre);


/** \brief Carga un valor de tipo int horas trabajadas al campo horasTrabajadas.
 *
 * \param this Employee*
 * \param horasTrabajadas int*
 * \return int (0 si sale todo ok.)(-1 si no sale todo ok)
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);


/** \brief Obtiene un valor de tipo int horas trabajadas del campo horasTrabajadas.
 *
 * \param this Employee*
 * \param horasTrabajadas int*
 * \return int (0 si sale todo ok.)(-1 si no sale todo ok)
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);


/** \brief Carga un valor de tipo int sueldo al campo sueldo.
 *
 * \param this Employee*
 * \param sueldo int*
 * \return int (0 si sale todo ok.)(-1 si no sale todo ok)
 *
 */
int employee_setSueldo(Employee* this,int sueldo);


/** \brief Obtiene un valor de tipo int sueldo del campo sueldo.
 *
 * \param this Employee*
 * \param horasTrabajadas int*
 * \return int (0 si sale todo ok.)(-1 si no sale todo ok)
 *
 */
int employee_getSueldo(Employee* this,int* sueldo);
//****************************************************************************************

#endif // employee_H_INCLUDED
