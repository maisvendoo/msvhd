#include "msvhd.h"

//-------------------------------------------------------------------
//
//-------------------------------------------------------------------
int main(int argc, char* argv[])
{
	CmdLineParser cmd;
	cmd_line_t cmd_line;

	cmd_line.append_footer = false;
	cmd_line.help = false;
	cmd_line.input_file = "";
	cmd_line.output_file = "";

	string msg = "";

	// Parse cmd line
	if (!cmd.parse(argc, argv, cmd_line, msg))
	{
		print_msg(msg);
		return -1;
	}

	/*if (cmd_line.help)
		return 0;*/

	VirtualDisk *vhd = new VirtualDisk();

	if (!vhd->process(cmd_line, msg))
	{
		print_msg(msg);
		delete vhd;

		return -1;
	}

	delete vhd;

	return 0;
}
