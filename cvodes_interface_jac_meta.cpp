/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

      #include "cvodes_interface_jac.hpp"
      #include <string>

      const std::string casadi::CvodesInterfaceJac::meta_doc=
      "\n"
"Interface to CVodes from the Sundials suite.\n"
"\n"
"A call to evaluate will integrate to the end.\n"
"\n"
"You can retrieve the entire state trajectory as follows, after the\n"
"evaluate call: Call reset. Then call integrate(t_i) and getOuput for a\n"
"series of times t_i.\n"
"\n"
"Note: depending on the dimension and structure of your problem, you\n"
"may experience a dramatic speed-up by using a sparse linear solver:\n"
"\n"
"\n"
"\n"
"::\n"
"\n"
"     intg.setOption(\"linear_solver\",\"csparse\")\n"
"     intg.setOption(\"linear_solver_type\",\"user_defined\")\n"
"\n"
"\n"
"\n"
"\n"
">List of available options\n"
"\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"|       Id        |      Type       |     Default     |   Description   |\n"
"+=================+=================+=================+=================+\n"
"| abstol          | OT_REAL         | 0.000           | Absolute        |\n"
"|                 |                 |                 | tolerence for   |\n"
"|                 |                 |                 | the IVP         |\n"
"|                 |                 |                 | solution        |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| abstolB         | OT_REAL         | GenericType()   | Absolute        |\n"
"|                 |                 |                 | tolerence for   |\n"
"|                 |                 |                 | the adjoint     |\n"
"|                 |                 |                 | sensitivity     |\n"
"|                 |                 |                 | solution        |\n"
"|                 |                 |                 | [default: equal |\n"
"|                 |                 |                 | to abstol]      |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| disable_interna | OT_BOOLEAN      | false           | Disable CVodes  |\n"
"| l_warnings      |                 |                 | internal        |\n"
"|                 |                 |                 | warning         |\n"
"|                 |                 |                 | messages        |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| exact_jacobian  | OT_BOOLEAN      | true            | Use exact       |\n"
"|                 |                 |                 | Jacobian        |\n"
"|                 |                 |                 | information for |\n"
"|                 |                 |                 | the forward     |\n"
"|                 |                 |                 | integration     |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| exact_jacobianB | OT_BOOLEAN      | GenericType()   | Use exact       |\n"
"|                 |                 |                 | Jacobian        |\n"
"|                 |                 |                 | information for |\n"
"|                 |                 |                 | the backward    |\n"
"|                 |                 |                 | integration     |\n"
"|                 |                 |                 | [default: equal |\n"
"|                 |                 |                 | to              |\n"
"|                 |                 |                 | exact_jacobian] |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| finite_differen | OT_BOOLEAN      | false           | Use finite      |\n"
"| ce_fsens        |                 |                 | differences to  |\n"
"|                 |                 |                 | approximate the |\n"
"|                 |                 |                 | forward         |\n"
"|                 |                 |                 | sensitivity     |\n"
"|                 |                 |                 | equations (if   |\n"
"|                 |                 |                 | AD is not       |\n"
"|                 |                 |                 | available)      |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| fsens_abstol    | OT_REAL         | GenericType()   | Absolute        |\n"
"|                 |                 |                 | tolerence for   |\n"
"|                 |                 |                 | the forward     |\n"
"|                 |                 |                 | sensitivity     |\n"
"|                 |                 |                 | solution        |\n"
"|                 |                 |                 | [default: equal |\n"
"|                 |                 |                 | to abstol]      |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| fsens_all_at_on | OT_BOOLEAN      | true            | Calculate all   |\n"
"| ce              |                 |                 | right hand      |\n"
"|                 |                 |                 | sides of the    |\n"
"|                 |                 |                 | sensitivity     |\n"
"|                 |                 |                 | equations at    |\n"
"|                 |                 |                 | once            |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| fsens_err_con   | OT_BOOLEAN      | true            | include the     |\n"
"|                 |                 |                 | forward         |\n"
"|                 |                 |                 | sensitivities   |\n"
"|                 |                 |                 | in all error    |\n"
"|                 |                 |                 | controls        |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| fsens_reltol    | OT_REAL         | GenericType()   | Relative        |\n"
"|                 |                 |                 | tolerence for   |\n"
"|                 |                 |                 | the forward     |\n"
"|                 |                 |                 | sensitivity     |\n"
"|                 |                 |                 | solution        |\n"
"|                 |                 |                 | [default: equal |\n"
"|                 |                 |                 | to reltol]      |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| fsens_scaling_f | OT_REALVECTOR   | GenericType()   | Scaling factor  |\n"
"| actors          |                 |                 | for the         |\n"
"|                 |                 |                 | components if   |\n"
"|                 |                 |                 | finite          |\n"
"|                 |                 |                 | differences is  |\n"
"|                 |                 |                 | used            |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| fsens_sensitivi | OT_INTEGERVECTO | GenericType()   | Specifies which |\n"
"| y_parameters    | R               |                 | components will |\n"
"|                 |                 |                 | be used when    |\n"
"|                 |                 |                 | estimating the  |\n"
"|                 |                 |                 | sensitivity     |\n"
"|                 |                 |                 | equations       |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| interpolation_t | OT_STRING       | \"hermite\"       | Type of         |\n"
"| ype             |                 |                 | interpolation   |\n"
"|                 |                 |                 | for the adjoint |\n"
"|                 |                 |                 | sensitivities ( |\n"
"|                 |                 |                 | hermite|polynom |\n"
"|                 |                 |                 | ial)            |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| iterative_solve | OT_STRING       | \"gmres\"         | (gmres|bcgstab| |\n"
"| r               |                 |                 | tfqmr)          |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| iterative_solve | OT_STRING       | GenericType()   | (gmres|bcgstab| |\n"
"| rB              |                 |                 | tfqmr)          |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| linear_multiste | OT_STRING       | \"bdf\"           | Integrator      |\n"
"| p_method        |                 |                 | scheme          |\n"
"|                 |                 |                 | (bdf|adams)     |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| linear_solver   | OT_STRING       | GenericType()   | A custom linear |\n"
"|                 |                 |                 | solver creator  |\n"
"|                 |                 |                 | function        |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| linear_solverB  | OT_STRING       | GenericType()   | A custom linear |\n"
"|                 |                 |                 | solver creator  |\n"
"|                 |                 |                 | function for    |\n"
"|                 |                 |                 | backwards       |\n"
"|                 |                 |                 | integration     |\n"
"|                 |                 |                 | [default: equal |\n"
"|                 |                 |                 | to              |\n"
"|                 |                 |                 | linear_solver]  |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| linear_solver_o | OT_DICT   | GenericType()   | Options to be   |\n"
"| ptions          |                 |                 | passed to the   |\n"
"|                 |                 |                 | linear solver   |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| linear_solver_o | OT_DICT   | GenericType()   | Options to be   |\n"
"| ptionsB         |                 |                 | passed to the   |\n"
"|                 |                 |                 | linear solver   |\n"
"|                 |                 |                 | for backwards   |\n"
"|                 |                 |                 | integration     |\n"
"|                 |                 |                 | [default: equal |\n"
"|                 |                 |                 | to linear_solve |\n"
"|                 |                 |                 | r_options]      |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| linear_solver_t | OT_STRING       | \"dense\"         | (user_defined|d |\n"
"| ype             |                 |                 | ense|banded|ite |\n"
"|                 |                 |                 | rative)         |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| linear_solver_t | OT_STRING       | GenericType()   | (user_defined|d |\n"
"| ypeB            |                 |                 | ense|banded|ite |\n"
"|                 |                 |                 | rative)         |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| lower_bandwidth | OT_INTEGER      | GenericType()   | Lower band-     |\n"
"|                 |                 |                 | width of banded |\n"
"|                 |                 |                 | Jacobian        |\n"
"|                 |                 |                 | (estimations)   |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| lower_bandwidth | OT_INTEGER      | GenericType()   | lower band-     |\n"
"| B               |                 |                 | width of banded |\n"
"|                 |                 |                 | jacobians for   |\n"
"|                 |                 |                 | backward        |\n"
"|                 |                 |                 | integration     |\n"
"|                 |                 |                 | [default: equal |\n"
"|                 |                 |                 | to lower_bandwi |\n"
"|                 |                 |                 | dth]            |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| max_krylov      | OT_INTEGER      | 10              | Maximum Krylov  |\n"
"|                 |                 |                 | subspace size   |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| max_krylovB     | OT_INTEGER      | GenericType()   | Maximum krylov  |\n"
"|                 |                 |                 | subspace size   |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| max_multistep_o | OT_INTEGER      | 5               |                 |\n"
"| rder            |                 |                 |                 |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| max_num_steps   | OT_INTEGER      | 10000           | Maximum number  |\n"
"|                 |                 |                 | of integrator   |\n"
"|                 |                 |                 | steps           |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| nonlinear_solve | OT_STRING       | \"newton\"        | (newton|functio |\n"
"| r_iteration     |                 |                 | nal)            |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| pretype         | OT_STRING       | \"none\"          | (none|left|righ |\n"
"|                 |                 |                 | t|both)         |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| pretypeB        | OT_STRING       | GenericType()   | (none|left|righ |\n"
"|                 |                 |                 | t|both)         |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| quad_err_con    | OT_BOOLEAN      | false           | Should the      |\n"
"|                 |                 |                 | quadratures     |\n"
"|                 |                 |                 | affect the step |\n"
"|                 |                 |                 | size control    |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| reltol          | OT_REAL         | 0.000           | Relative        |\n"
"|                 |                 |                 | tolerence for   |\n"
"|                 |                 |                 | the IVP         |\n"
"|                 |                 |                 | solution        |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| reltolB         | OT_REAL         | GenericType()   | Relative        |\n"
"|                 |                 |                 | tolerence for   |\n"
"|                 |                 |                 | the adjoint     |\n"
"|                 |                 |                 | sensitivity     |\n"
"|                 |                 |                 | solution        |\n"
"|                 |                 |                 | [default: equal |\n"
"|                 |                 |                 | to reltol]      |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| sensitivity_met | OT_STRING       | \"simultaneous\"  | (simultaneous|s |\n"
"| hod             |                 |                 | taggered)       |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| steps_per_check | OT_INTEGER      | 20              | Number of steps |\n"
"| point           |                 |                 | between two     |\n"
"|                 |                 |                 | consecutive     |\n"
"|                 |                 |                 | checkpoints     |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| stop_at_end     | OT_BOOLEAN      | true            | Stop the        |\n"
"|                 |                 |                 | integrator at   |\n"
"|                 |                 |                 | the end of the  |\n"
"|                 |                 |                 | interval        |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| upper_bandwidth | OT_INTEGER      | GenericType()   | Upper band-     |\n"
"|                 |                 |                 | width of banded |\n"
"|                 |                 |                 | Jacobian        |\n"
"|                 |                 |                 | (estimations)   |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| upper_bandwidth | OT_INTEGER      | GenericType()   | Upper band-     |\n"
"| B               |                 |                 | width of banded |\n"
"|                 |                 |                 | jacobians for   |\n"
"|                 |                 |                 | backward        |\n"
"|                 |                 |                 | integration     |\n"
"|                 |                 |                 | [default: equal |\n"
"|                 |                 |                 | to upper_bandwi |\n"
"|                 |                 |                 | dth]            |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| use_preconditio | OT_BOOLEAN      | false           | Precondition an |\n"
"| ner             |                 |                 | iterative       |\n"
"|                 |                 |                 | solver          |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"| use_preconditio | OT_BOOLEAN      | GenericType()   | Precondition an |\n"
"| nerB            |                 |                 | iterative       |\n"
"|                 |                 |                 | solver for the  |\n"
"|                 |                 |                 | backwards       |\n"
"|                 |                 |                 | problem         |\n"
"|                 |                 |                 | [default: equal |\n"
"|                 |                 |                 | to use_precondi |\n"
"|                 |                 |                 | tioner]         |\n"
"+-----------------+-----------------+-----------------+-----------------+\n"
"\n"
"\n"
">List of available monitors\n"
"\n"
"+---------+\n"
"|   Id    |\n"
"+=========+\n"
"| djacB   |\n"
"+---------+\n"
"| psetupB |\n"
"+---------+\n"
"| res     |\n"
"+---------+\n"
"| resB    |\n"
"+---------+\n"
"| resQB   |\n"
"+---------+\n"
"| reset   |\n"
"+---------+\n"
"\n"
"\n"
">List of available stats\n"
"\n"
"+-------------+\n"
"|     Id      |\n"
"+=============+\n"
"| nlinsetups  |\n"
"+-------------+\n"
"| nlinsetupsB |\n"
"+-------------+\n"
"| nsteps      |\n"
"+-------------+\n"
"| nstepsB     |\n"
"+-------------+\n"
"\n"
"\n"
"\n"
"\n"
;
