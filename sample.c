void pickup_forks(int p)
{
	// lock mutex
	pthread_mutex_lock(&available);
	state[p] = eating;
	// random (60 - 180 secs)
	// unlock mutex
}

int check_others(int p)
{
	// if sideways in hungry state -> convert to eating
	//if (state[abs(i-1)] == hungry)
	return 0;
}

void return_forks(int p)
{
	// unlock mutex
	pthread_mutex_unlock(&available);
	state[p] = thinking;
	check_others(p);
}
