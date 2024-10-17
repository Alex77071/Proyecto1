/**
 * Clase MVCImitador Contiene información de un imitador
 * 
 * @author Iván Alexander Cortés Pérez
 */
package mvc;

import controller.ImitadorControlador;
import model.ImitadorModelo;
import view.ImitadorVista;

public class MVCImitador {
	  public static void main(String[] args) {
	        ImitadorVista vista = new ImitadorVista();
	        ImitadorModelo modelo = new ImitadorModelo();
	        new ImitadorControlador(vista, modelo);

	        vista.setVisible(true);
	    }
}
