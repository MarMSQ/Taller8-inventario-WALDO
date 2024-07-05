void ingresarAlimentos(char alimentos[][30], float precios[], int cantidades[], int numeroitem, int nuevosAlimentos);

void imprimirAlimentos(char alimentos[][30], float precios[], int cantidades[], int n);

int BuscarAlimento(char alimentos[][30], char nombreAlimento[], int n);

void imprimirAlimentoIndex(char alimentos[][30], float precios[], int cantidades[], int index);

void editarAlimento(char alimentos[][30], float precios[], int cantidades[], int n);

void eliminarAlimento(char alimentos[][30], float precios[], int cantidades[], int *n);

void imprimiradvertencia();

void opcionIngresarAlimentos(char alimentos[][30], float precios[], int cantidades[], int *numeroitem, int maximoinventario);

void opcionBuscarAlimento(char alimentos[][30], float precios[], int cantidades[], int numeroitem);

void leeralimentos(char alimentos[][30], char *alimentodoc);

void leerprecios(float precios[], char *preciosdoc);

void leercantidades(int cantidades[], char *cantidadesdoc);

void guardaralimentos(char alimentos[][30], char *alimentodoc);

void guardarprecios(float precios[], char *preciosdoc);

void guardarcantidades(int cantidades[], char *cantidadesdoc);