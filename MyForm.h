#pragma once
#include "Controladora.h"

namespace PC2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			objcontroladora = new Controladora();
			bmpsoldado = gcnew Bitmap("Soldado.png");
			bmpbala = gcnew Bitmap("balas.png");
			bmpdc = gcnew Bitmap("DoradaC.png");
			bmppc = gcnew Bitmap("PlateadaC.png");
			bmpd = gcnew Bitmap("Dorada.png");
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
			delete objcontroladora, bmpsoldado,bmpbala,bmpdc,bmppc,bmpd;
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		Controladora* objcontroladora;
		Bitmap^ bmpsoldado;
		Bitmap^ bmpbala;
		Bitmap^ bmpdc;
		Bitmap^ bmppc;
		Bitmap^ bmpd;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1044, 638);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ g = CreateGraphics();
		BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^ bf = espacio->Allocate(g, ClientRectangle);
		bf->Graphics->Clear(Color::White);
		objcontroladora->Dibujar_Soldado(bf->Graphics, bmpsoldado);
		objcontroladora->Dibujar_Bala(bf->Graphics, bmpbala);
		objcontroladora->Insertar_Monedas();
		objcontroladora->Dibujar_DoradaC(bf->Graphics, bmpdc);
		objcontroladora->Dibujar_PlateadaC(bf->Graphics, bmppc);
		objcontroladora->Dibujar_Dorada(bf->Graphics, bmpd);
		if (objcontroladora->Colision2() == true)
		{
			System::Drawing::Font^ k = gcnew System::Drawing::Font("Arian", 20);
			System::Drawing::SolidBrush^ sbh = gcnew System::Drawing::SolidBrush(Color::DarkRed);
			timer1->Enabled = false;
			bf->Graphics->Clear(Color::White);

			bf->Graphics->DrawString("Perdio", k, sbh, 40, 40);
		}
		bf->Render(g);
		delete bf, espacio, g;
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Left) objcontroladora->Desplazar_Soldado(direccion::izquierda);
		if (e->KeyCode == Keys::Right)objcontroladora->Desplazar_Soldado(direccion::derecha);
		if (e->KeyCode == Keys::Up) objcontroladora->Desplazar_Soldado(direccion::arriba);
		if (e->KeyCode == Keys::Down)objcontroladora->Desplazar_Soldado(direccion::abajo);
		if (e->KeyCode == Keys::Space)objcontroladora->Disparar();
	}
	};
}
