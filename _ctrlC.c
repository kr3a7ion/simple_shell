/**
 * _ctrlC - Ctrl+C signal handler for shell
 *
 * @prmSignal: signal value (unused)
 */
void _ctrlC(int prmSignal __attribute__((unused)))
{
    _puts("\n");
    _prompt();
}

