#pragma once

#define _USE_MATH_DEFINES
#include <cmath>
// #include <Windows.h>
// #include <process.h>

double x1;
double x2;
double step;
int eps;
double precision = 1;

double sinTeylor(double rad, int eps, double precision) {
	double delta = rad;
	double sinus = rad;
	double n = 1;

	do {
		delta *= -1 * rad * rad / ((n + 1) * (n + 2));
		sinus += delta;
		//printf("%f\n", sinus);
		n += 2;
	} while (fabs(delta) >= precision);

	sinus *= pow(10, 6 - eps);
	sinus /= pow(10, 6 - eps);
	//printf("%f\n", sinus);

	return sinus;
}

double cosTeylor(double rad, int eps, double precision) {
	double delta = 1;
	double cosin = 1;
	double n = 1;

	do {
		delta *= -1 * rad * rad / (2 * n * (2 * n - 1));
		cosin += delta;
		n += 1;
	} while (fabs(delta) >= precision);

	return cosin;
}

namespace CppWinForm1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			Control::CheckForIllegalCrossThreadCalls = false;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBoxX1;
	private: System::Windows::Forms::TextBox^  textBoxX2;
	private: System::Windows::Forms::TextBox^  textBoxStep;
	private: System::Windows::Forms::Button^  buttonCalculateSin;

	private: System::Windows::Forms::TextBox^  textBoxOut;

	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  buttonCalculateCos;
	private: System::Windows::Forms::NumericUpDown^  numericUpDownPrecision;
	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel1;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;
	private: System::Windows::Forms::Button^  buttonCancel;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorkerCos;




	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBoxX1 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxX2 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxStep = (gcnew System::Windows::Forms::TextBox());
			this->buttonCalculateSin = (gcnew System::Windows::Forms::Button());
			this->textBoxOut = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->buttonCalculateCos = (gcnew System::Windows::Forms::Button());
			this->numericUpDownPrecision = (gcnew System::Windows::Forms::NumericUpDown());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->toolStripStatusLabel1 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->buttonCancel = (gcnew System::Windows::Forms::Button());
			this->backgroundWorkerCos = (gcnew System::ComponentModel::BackgroundWorker());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownPrecision))->BeginInit();
			this->statusStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// chart1
			// 
			this->chart1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			chartArea1->AlignmentOrientation = static_cast<System::Windows::Forms::DataVisualization::Charting::AreaAlignmentOrientations>((System::Windows::Forms::DataVisualization::Charting::AreaAlignmentOrientations::Vertical | System::Windows::Forms::DataVisualization::Charting::AreaAlignmentOrientations::Horizontal));
			chartArea1->CursorX->Interval = 0.1;
			chartArea1->CursorX->IntervalOffsetType = System::Windows::Forms::DataVisualization::Charting::DateTimeIntervalType::Number;
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(158, 12);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series1->Legend = L"Legend1";
			series1->Name = L"Teylor";
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series2->Legend = L"Legend1";
			series2->Name = L"ideal";
			this->chart1->Series->Add(series1);
			this->chart1->Series->Add(series2);
			this->chart1->Size = System::Drawing::Size(473, 256);
			this->chart1->TabIndex = 0;
			this->chart1->TabStop = false;
			this->chart1->Text = L"chart1";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(21, 15);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(18, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"x1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(21, 41);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(18, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"x2";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 67);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(27, 13);
			this->label3->TabIndex = 3;
			this->label3->Text = L"step";
			// 
			// textBoxX1
			// 
			this->textBoxX1->Location = System::Drawing::Point(45, 12);
			this->textBoxX1->Name = L"textBoxX1";
			this->textBoxX1->Size = System::Drawing::Size(107, 20);
			this->textBoxX1->TabIndex = 4;
			this->textBoxX1->Text = L"0";
			this->textBoxX1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBoxX1_KeyPress);
			// 
			// textBoxX2
			// 
			this->textBoxX2->Location = System::Drawing::Point(45, 38);
			this->textBoxX2->Name = L"textBoxX2";
			this->textBoxX2->Size = System::Drawing::Size(107, 20);
			this->textBoxX2->TabIndex = 5;
			this->textBoxX2->Text = L"360";
			this->textBoxX2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBoxX2_KeyPress);
			// 
			// textBoxStep
			// 
			this->textBoxStep->Location = System::Drawing::Point(45, 64);
			this->textBoxStep->Name = L"textBoxStep";
			this->textBoxStep->Size = System::Drawing::Size(107, 20);
			this->textBoxStep->TabIndex = 6;
			this->textBoxStep->Text = L"1";
			this->textBoxStep->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBoxStep_KeyPress);
			// 
			// buttonCalculateSin
			// 
			this->buttonCalculateSin->Location = System::Drawing::Point(12, 116);
			this->buttonCalculateSin->Name = L"buttonCalculateSin";
			this->buttonCalculateSin->Size = System::Drawing::Size(67, 46);
			this->buttonCalculateSin->TabIndex = 8;
			this->buttonCalculateSin->Text = L"Calculate sin";
			this->buttonCalculateSin->UseVisualStyleBackColor = true;
			this->buttonCalculateSin->Click += gcnew System::EventHandler(this, &MyForm::buttonCalculateSin_Click);
			// 
			// textBoxOut
			// 
			this->textBoxOut->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBoxOut->Location = System::Drawing::Point(12, 277);
			this->textBoxOut->Multiline = true;
			this->textBoxOut->Name = L"textBoxOut";
			this->textBoxOut->ReadOnly = true;
			this->textBoxOut->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBoxOut->Size = System::Drawing::Size(619, 59);
			this->textBoxOut->TabIndex = 0;
			this->textBoxOut->TabStop = false;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(9, 92);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(49, 13);
			this->label4->TabIndex = 11;
			this->label4->Text = L"precision";
			// 
			// buttonCalculateCos
			// 
			this->buttonCalculateCos->Location = System::Drawing::Point(85, 116);
			this->buttonCalculateCos->Name = L"buttonCalculateCos";
			this->buttonCalculateCos->Size = System::Drawing::Size(67, 46);
			this->buttonCalculateCos->TabIndex = 9;
			this->buttonCalculateCos->Text = L"Calculate cos";
			this->buttonCalculateCos->UseVisualStyleBackColor = true;
			this->buttonCalculateCos->Click += gcnew System::EventHandler(this, &MyForm::buttonCalculateCos_Click);
			// 
			// numericUpDownPrecision
			// 
			this->numericUpDownPrecision->Location = System::Drawing::Point(64, 90);
			this->numericUpDownPrecision->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 15, 0, 0, 0 });
			this->numericUpDownPrecision->Name = L"numericUpDownPrecision";
			this->numericUpDownPrecision->Size = System::Drawing::Size(88, 20);
			this->numericUpDownPrecision->TabIndex = 7;
			// 
			// statusStrip1
			// 
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->toolStripStatusLabel1 });
			this->statusStrip1->Location = System::Drawing::Point(0, 339);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(643, 22);
			this->statusStrip1->TabIndex = 14;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// toolStripStatusLabel1
			// 
			this->toolStripStatusLabel1->Name = L"toolStripStatusLabel1";
			this->toolStripStatusLabel1->Size = System::Drawing::Size(0, 17);
			this->toolStripStatusLabel1->ToolTipText = L" ";
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->WorkerSupportsCancellation = true;
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm::backgroundWorker1_DoWork);
			this->backgroundWorker1->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &MyForm::backgroundWorker1_RunWorkerCompleted);
			// 
			// buttonCancel
			// 
			this->buttonCancel->Location = System::Drawing::Point(12, 169);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(140, 23);
			this->buttonCancel->TabIndex = 10;
			this->buttonCancel->Text = L"Cancel";
			this->buttonCancel->UseVisualStyleBackColor = true;
			this->buttonCancel->Click += gcnew System::EventHandler(this, &MyForm::buttonCancel_Click);
			// 
			// backgroundWorkerCos
			// 
			this->backgroundWorkerCos->WorkerSupportsCancellation = true;
			this->backgroundWorkerCos->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm::backgroundWorkerCos_DoWork);
			this->backgroundWorkerCos->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &MyForm::backgroundWorkerCos_RunWorkerCompleted);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(643, 361);
			this->Controls->Add(this->buttonCancel);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->numericUpDownPrecision);
			this->Controls->Add(this->buttonCalculateCos);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBoxOut);
			this->Controls->Add(this->buttonCalculateSin);
			this->Controls->Add(this->textBoxStep);
			this->Controls->Add(this->textBoxX2);
			this->Controls->Add(this->textBoxX1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->chart1);
			this->MinimumSize = System::Drawing::Size(525, 400);
			this->Name = L"MyForm";
			this->Text = L"lab4.1v2";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownPrecision))->EndInit();
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void textBoxX1_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
		// Only allow 1 decimal point
		if (e->KeyChar == ',')
		{
			if (this->textBoxX1->Text->Contains(",") && !this->textBoxX1->SelectedText->Contains(","))
				e->Handled = true;
		}
		else if (e->KeyChar == '-')
		{
			if (this->textBoxX1->Text->Contains("-") && !this->textBoxX1->SelectedText->Contains("-"))
				e->Handled = true;
			else if (textBoxX1->SelectionStart != 0)
				e->Handled = true;
		}
		// Accept only digits "." and the Backspace character
		else if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08)
			e->Handled = true;
	}
	private: System::Void textBoxX2_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
		// Only allow 1 decimal point
		if (e->KeyChar == '.')
		{
			if (this->textBoxX2->Text->Contains(",") && !this->textBoxX2->SelectedText->Contains(","))
				e->Handled = true;
		}
		else if (e->KeyChar == '-')
		{
			if (this->textBoxX2->Text->Contains("-") && !this->textBoxX2->SelectedText->Contains("-"))
				e->Handled = true;
			else if (textBoxX2->SelectionStart != 0)
				e->Handled = true;
		}
		// Accept only digits "." and the Backspace character
		else if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08)
			e->Handled = true;
	}
	private: System::Void textBoxStep_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
		// Only allow 1 decimal point
		if (e->KeyChar == ',')
		{
			if (this->textBoxStep->Text->Contains(",") && !this->textBoxStep->SelectedText->Contains(","))
				e->Handled = true;
		}
		else if (e->KeyChar == '-')
		{
			if (this->textBoxStep->Text->Contains("-") && !this->textBoxStep->SelectedText->Contains("-"))
				e->Handled = true;
			else if (textBoxStep->SelectionStart != 0)
				e->Handled = true;
		}
		// Accept only digits "." and the Backspace character
		else if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08)
			e->Handled = true;
	}

	int showMessage(String ^mes) {
		MessageBox::Show(mes,
			"lab4.1v2", MessageBoxButtons::OK,
			MessageBoxIcon::Asterisk);

		return 0;
	}

	int inputCheck() {
		int response = 0;

		if (textBoxX1->Text == "") response = 1;

		if (textBoxX2->Text == "") response = 1;

		if (textBoxStep->Text == "") response = 1;

		if (response) showMessage("Enter all values!");

		return response;
	}

	int drawIdealSin(double x1, double x2) {
		for (double x = x1; x <= x2; x += 1) {
			double rad = x * M_PI / 180;
			double sin = Math::Sin(rad);
			chart1->Series["ideal"]->Points->AddXY(rad, sin);
		}

		return 0;
	}
	int drawIdealCos(double x1, double x2) {
		for (double x = x1; x <= x2; x += 1) {
			double rad = x * M_PI / 180;
			double cos = Math::Cos(rad);
			chart1->Series["ideal"]->Points->AddXY(rad, cos);
		}

		return 0;
	}

	int bgWorkersPending() {
		if (backgroundWorker1->IsBusy || backgroundWorkerCos->IsBusy) {
			return 1;
		}
		return 0;
	}

	private: System::Void buttonCalculateSin_Click(System::Object^  sender, System::EventArgs^  e) {
		if (bgWorkersPending()) showMessage("Error, another bgWorker is working!\nYou should cancel bgWorkers before");
		else {
			if (inputCheck() == 0) {

				toolStripStatusLabel1->Text = " ";

				x1 = Convert::ToDouble(textBoxX1->Text);
				x2 = Convert::ToDouble(textBoxX2->Text);
				step = Convert::ToDouble(textBoxStep->Text);
				eps = Convert::ToInt32(numericUpDownPrecision->Text);

				if (step == 0) {
					showMessage("Step can't be 0");
					toolStripStatusLabel1->Text = "Error!";
					return;
				}
				if (x1 < x2 && step < 0) {
					showMessage("If x1 < x2 step should be positive");
					toolStripStatusLabel1->Text = "Error!";
					return;
				}
				if (x1 > x2 && step > 0) {
					showMessage("If x1 > x2 step should be negative");
					toolStripStatusLabel1->Text = "Error!";
					return;
				}

				toolStripStatusLabel1->Text = "Calculating sin...";

				for (int i = 0; i < eps; i++) {
					precision *= 0.1;
				}

				chart1->Series["Teylor"]->Points->Clear();
				//chart1->Series["cmath"]->Points->Clear();
				chart1->Series["ideal"]->Points->Clear();

				textBoxOut->Text = "";

				backgroundWorker1->RunWorkerAsync(1);

				drawIdealSin(x1, x2);

			}
		}
	}
	private: System::Void buttonCalculateCos_Click(System::Object^  sender, System::EventArgs^  e) {
		if (bgWorkersPending()) showMessage("Error, another bgWorker is working!\nYou should cancel bgWorkers before");
		else {
			if (inputCheck() == 0) {

				toolStripStatusLabel1->Text = " ";

				x1 = Convert::ToDouble(textBoxX1->Text);
				x2 = Convert::ToDouble(textBoxX2->Text);
				step = Convert::ToDouble(textBoxStep->Text);
				eps = Convert::ToInt32(numericUpDownPrecision->Text);

				if (step == 0) {
					showMessage("Step can't be 0");
					toolStripStatusLabel1->Text = "Error!";
					return;
				}
				if (x1 < x2 && step < 0) {
					showMessage("If x1 < x2 step should be positive");
					toolStripStatusLabel1->Text = "Error!";
					return;
				}
				if (x1 > x2 && step > 0) {
					showMessage("If x1 > x2 step should be negative");
					toolStripStatusLabel1->Text = "Error!";
					return;
				}

				toolStripStatusLabel1->Text = "Calculating cos...";

				for (int i = 0; i < eps; i++) {
					precision *= 0.1;
				}

				chart1->Series["Teylor"]->Points->Clear();
				//chart1->Series["cmath"]->Points->Clear();
				chart1->Series["ideal"]->Points->Clear();

				textBoxOut->Text = "";

				backgroundWorkerCos->RunWorkerAsync(1);

				drawIdealCos(x1, x2);
			}
		}
	}
	private: System::Void buttonCancel_Click(System::Object^  sender, System::EventArgs^  e) {
		backgroundWorker1->CancelAsync();
		backgroundWorkerCos->CancelAsync();
	}

	private: System::Void backgroundWorker1_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
		while (true)
		{
			if (backgroundWorker1->CancellationPending) //if it was cancelled
			{
				e->Cancel = true;
				break;
			}

			if (x1 < x2) {
				for (double x = x1; x <= x2; x += step) {
					if (backgroundWorker1->CancellationPending) //if it was cancelled
					{
						e->Cancel = true;
						break;
					}

					double rad = x * M_PI / 180;
					double sinT = sinTeylor(rad, eps, precision);
					double sinM = Math::Sin(rad);

					textBoxOut->Text += x;
					textBoxOut->Text += " | ";
					textBoxOut->Text += rad;
					textBoxOut->Text += " | ";
					textBoxOut->Text += sinT;
					textBoxOut->Text += " | ";
					textBoxOut->Text += sinM;

					textBoxOut->Text += "\r\n";

					chart1->Series["Teylor"]->Points->AddXY(rad, sinT);
					//chart1->Series["cmath"]->Points->AddXY(rad, sinM);

				}
				break;
			}
			else {
				for (double x = x2; x >= x1; x -= step) {
					double rad = x * M_PI / 180;
					double sinT = sinTeylor(rad, eps, precision);
					double sinM = Math::Sin(rad);

					textBoxOut->Text += x;
					textBoxOut->Text += " | ";
					textBoxOut->Text += rad;
					textBoxOut->Text += " | ";
					textBoxOut->Text += sinT;
					textBoxOut->Text += " | ";
					textBoxOut->Text += sinM;

					textBoxOut->Text += "\r\n";

					chart1->Series["Teylor"]->Points->AddXY(rad, sinT);
					//chart1->Series["cmath"]->Points->AddXY(rad, sinM);

				}
				break;
			}
		}
	}
	private: System::Void backgroundWorker1_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e) {
		if (e->Cancelled)    //Messages for the events
		{
			toolStripStatusLabel1->Text = "Canceled";
		}
		else
		{
			toolStripStatusLabel1->Text = "Done";
		}
	}
	private: System::Void backgroundWorkerCos_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
		while (true)
		{
			if (backgroundWorkerCos->CancellationPending) //if it was cancelled
			{
				e->Cancel = true;
				break;
			}

			if (x1 < x2) {
				for (double x = x1; x <= x2; x += step) {
					if (backgroundWorkerCos->CancellationPending) //if it was cancelled
					{
						e->Cancel = true;
						break;
					}

					double rad = x * M_PI / 180;
					double cosT = cosTeylor(rad, eps, precision);
					double cosM = Math::Cos(rad);

					textBoxOut->Text += x;
					textBoxOut->Text += " | ";
					textBoxOut->Text += rad;
					textBoxOut->Text += " | ";
					textBoxOut->Text += cosT;
					textBoxOut->Text += " | ";
					textBoxOut->Text += cosM;

					textBoxOut->Text += "\r\n";

					chart1->Series["Teylor"]->Points->AddXY(rad, cosT);
					//chart1->Series["cmath"]->Points->AddXY(rad, sinM);
				}
				break;
			}
			else {
				for (double x = x2; x >= x1; x -= step) {
					double rad = x * M_PI / 180;
					double cosT = cosTeylor(rad, eps, precision);
					double cosM = Math::Cos(rad);

					textBoxOut->Text += x;
					textBoxOut->Text += " | ";
					textBoxOut->Text += rad;
					textBoxOut->Text += " | ";
					textBoxOut->Text += cosT;
					textBoxOut->Text += " | ";
					textBoxOut->Text += cosM;

					textBoxOut->Text += "\r\n";

					chart1->Series["Teylor"]->Points->AddXY(rad, cosT);
					//chart1->Series["cmath"]->Points->AddXY(rad, sinM);

				}
				toolStripStatusLabel1->Text = "Done!";
				break;
			}
		}
	}
	private: System::Void backgroundWorkerCos_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e) {
		if (e->Cancelled)    //Messages for the events
		{
			toolStripStatusLabel1->Text = "Canceled";
		}
		else
		{
			toolStripStatusLabel1->Text = "Done";
		}
	}
};
}



