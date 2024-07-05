void ingresarAlimentos(char alimentos[][30], float precios[], int cantidades[], int numeroitem, int nuevosAlimentos);

void imprimirAlimentos(char alimentos[][30], float precios[], int cantidades[], int n);

void imprimiradvertencia();

int BuscarAlimento(char alimentos[][30], char nombreAlimento[], int n);

void imprimirAlimentoIndex(char alimentos[][30], float precios[], int cantidades[], int index);

void editarAlimento(char alimentos[][30], float precios[], int cantidades[], int n);

void eliminarAlimento(char alimentos[][30], float precios[], int cantidades[], int *n);

void opcionIngresarAlimentos(char alimentos[][30], float precios[], int cantidades[], int *numeroitem, int maximoinventario);

void opcionBuscarAlimento(char alimentos[][30], float precios[], int cantidades[], int numeroitem);

int leeralimentos(char alimentos[][30], char *alimentodoc);

void leerprecios(float precios[], char *preciosdoc, int n);

void leercantidades(int cantidades[], char *cantidadesdoc, int n);

void guardaralimentos(char alimentos[][30], char *alimentodoc, int n);

void guardarprecios(float precios[], char *preciosdoc, int n);

void guardarcantidades(int cantidades[], char *cantidadesdoc, int n);