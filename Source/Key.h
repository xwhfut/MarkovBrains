/*
  ==============================================================================

    Key.h
    Created: 8 Nov 2018 6:53:50pm by Kurt
    Last Edit:  Kurt

    - Very Unfinished (clearly)
    - On hold until task is deemed necessary on Asana
    - Best to learn exactly how MIDI information is processed to make this class
      as efficient as possible.

  ==============================================================================
*/

class Key
{
    public:
      
    // Functions to modify the private notes_enable array.
    void a_en();
    void b_en();
    void c_en();
    void d_en();
    void e_en();
    void f_en();
    void g_en();
    void a_flat_en();
    void b_flat_en();
    void d_flat_en();
    void e_flat_en();
    void g_flat_en();

    private:
    // Allows scales to enable certain notes
    bool notes_enable[12];

};
