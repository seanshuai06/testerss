#ifndef __COMMAND_CLASS__
#define __COMMAND_CLASS__

#include "composite.h"

class Command {
	protected:
		Base* root;
		
	public:
		Command() { };
		double execute() {
			return root->evaluate();
		};
		Base* get_root() {
			return root;
		};
};

class OpCommand : public Command {
	//OpCommand Code Here
	public:
	OpCommand(int i) {
		root = new Op( static_cast<double>(i) );
	}
	
};
class AddCommand : public Command {
	//AddCommand Code Here	
	public:
	AddCommand(Command* cmd, int i){
		root = new Add(cmd->get_root(), new Op(static_cast<double>(i)  ) );
	}
};

class SubCommand : public Command {
	//SubCommand Code Here
	public:
	SubCommand(Command* cmd, int i){
		root = new Sub(cmd->get_root(), new Op(static_cast<double>(i)  ) );
	}
};

class MultCommand : public Command {
	//MultCommand Code Here
	public:
	MultCommand(Command* cmd, int i){
		root = new Mult(cmd->get_root(), new Op(static_cast<double>(i)  ) );
	}
};

class SqrCommand : public Command {
	//SqrCommand Code Here
	public:
	SqrCommand(Command* cmd){
		root = new Sqr(cmd->get_root());
	}
};

#endif //__COMMAND_CLASS__
