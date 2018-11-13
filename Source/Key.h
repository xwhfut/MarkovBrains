/*
  ==============================================================================

    Key.h
    Created: 8 Nov 2018 6:53:50pm
    Author:  Kurt

  ==============================================================================
*/

#pragma once

class Key
{
    public:

    

    void c_en();
    void d_en();
    void e_en();
    void f_en();
    void g_en();
    void a_en();
    void b_en();
    void d_flat_en();
    void e_flat_en();
    void g_flat_en();
    void a_flat_en();
    void b_flat_en();

    private:
    bool notes_enable[12];

}
