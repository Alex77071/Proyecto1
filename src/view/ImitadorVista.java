/**
 * Clase ImitadorVista Contiene información de un imitador
 * 
 * @author Iván Alexander Cortés Pérez
 */
package view;

import javax.swing.*;
import java.awt.*;

public class ImitadorVista extends JFrame {
    /**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private JRadioButton[] radioButtonsOriginal;
    private JCheckBox[] checkBoxesOriginal;
    private JTextField campoTextoOriginal;
    private JComboBox<String> comboBoxOriginal;
    private JSpinner spinnerOriginal;

    private JRadioButton[] radioButtonsEspejo;
    private JCheckBox[] checkBoxesEspejo;
    private JTextField campoTextoEspejo;
    private JComboBox<String> comboBoxEspejo;
    private JSpinner spinnerEspejo;

    public ImitadorVista() {
        setTitle("Imitador");
        setSize(400, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new GridLayout(2, 1, 10, 10));  // GridLayout con 2 filas
        setLocationRelativeTo(null);

        // Paneles para secciones
        JPanel panelOriginal = new JPanel(new GridLayout(4, 3, 10, 10));
        JPanel panelEspejo = new JPanel(new GridLayout(4, 3, 10, 10));

        // Componentes originales
        JLabel labelOriginal = new JLabel("Original");
        radioButtonsOriginal = new JRadioButton[3];
        radioButtonsOriginal[0] = new JRadioButton("Opcion 1");
        radioButtonsOriginal[1] = new JRadioButton("Opcion 2");
        radioButtonsOriginal[2] = new JRadioButton("Opcion 3");

        ButtonGroup grupoOriginal = new ButtonGroup();
        for (JRadioButton rb : radioButtonsOriginal) {
            grupoOriginal.add(rb);
        }

        checkBoxesOriginal = new JCheckBox[3];
        checkBoxesOriginal[0] = new JCheckBox("Opcion 4");
        checkBoxesOriginal[1] = new JCheckBox("Opcion 5");
        checkBoxesOriginal[2] = new JCheckBox("Opcion 6");

        campoTextoOriginal = new JTextField(10);
        comboBoxOriginal = new JComboBox<>(new String[]{"Item 1", "Item 2", "Item 3"});
        spinnerOriginal = new JSpinner(new SpinnerNumberModel(20, 0, 100, 1));

        // Componentes espejo
        JLabel labelEspejo = new JLabel("Espejo");
        radioButtonsEspejo = new JRadioButton[3];
        radioButtonsEspejo[0] = new JRadioButton("Opcion 1");
        radioButtonsEspejo[1] = new JRadioButton("Opcion 2");
        radioButtonsEspejo[2] = new JRadioButton("Opcion 3");

        ButtonGroup grupoEspejo = new ButtonGroup();
        for (JRadioButton rb : radioButtonsEspejo) {
            grupoEspejo.add(rb);
        }

        checkBoxesEspejo = new JCheckBox[3];
        checkBoxesEspejo[0] = new JCheckBox("Opcion 4");
        checkBoxesEspejo[1] = new JCheckBox("Opcion 5");
        checkBoxesEspejo[2] = new JCheckBox("Opcion 6");

        campoTextoEspejo = new JTextField(10);
        campoTextoEspejo.setEditable(false);
        comboBoxEspejo = new JComboBox<>(new String[]{"Item 1", "Item 2", "Item 3"});
        comboBoxEspejo.setEnabled(false);
        spinnerEspejo = new JSpinner(new SpinnerNumberModel(20, 0, 100, 1));
        spinnerEspejo.setEnabled(false);

        // Añadir componentes a los paneles
        panelOriginal.add(labelOriginal);
        for (JRadioButton rb : radioButtonsOriginal) panelOriginal.add(rb);
        for (JCheckBox cb : checkBoxesOriginal) panelOriginal.add(cb);
        panelOriginal.add(campoTextoOriginal);
        panelOriginal.add(comboBoxOriginal);
        panelOriginal.add(spinnerOriginal);

        panelEspejo.add(labelEspejo);
        for (JRadioButton rb : radioButtonsEspejo) panelEspejo.add(rb);
        for (JCheckBox cb : checkBoxesEspejo) panelEspejo.add(cb);
        panelEspejo.add(campoTextoEspejo);
        panelEspejo.add(comboBoxEspejo);
        panelEspejo.add(spinnerEspejo);

        // Añadir paneles a la ventana
        add(panelOriginal);
        add(panelEspejo);
    }

    public JRadioButton[] getRadioButtonsOriginal() {
        return radioButtonsOriginal;
    }

    public JCheckBox[] getCheckBoxesOriginal() {
        return checkBoxesOriginal;
    }

    public JTextField getCampoTextoOriginal() {
        return campoTextoOriginal;
    }

    public JComboBox<String> getComboBoxOriginal() {
        return comboBoxOriginal;
    }

    public JSpinner getSpinnerOriginal() {
        return spinnerOriginal;
    }

    public JRadioButton[] getRadioButtonsEspejo() {
        return radioButtonsEspejo;
    }

    public JCheckBox[] getCheckBoxesEspejo() {
        return checkBoxesEspejo;
    }

    public JTextField getCampoTextoEspejo() {
        return campoTextoEspejo;
    }

    public JComboBox<String> getComboBoxEspejo() {
        return comboBoxEspejo;
    }

    public JSpinner getSpinnerEspejo() {
        return spinnerEspejo;
    }
}
