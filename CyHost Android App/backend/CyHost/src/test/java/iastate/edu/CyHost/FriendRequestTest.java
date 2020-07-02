
package iastate.edu.CyHost;

import static org.junit.Assert.assertEquals;

import static org.mockito.Mockito.when;

import java.util.ArrayList;

import java.util.List;


import iastate.edu.Friends.*;
import org.junit.Before;
import org.junit.Test;
import org.mockito.InjectMocks;
import org.mockito.Mock;
import org.mockito.MockitoAnnotations;

/**
 * @author Daniel Nikolic
 */
public class FriendRequestTest 
{
	@Mock
	FriendRequestRepository repo;

	@Before
	public void init() 
	{
		MockitoAnnotations.initMocks(this);
	}

	@Test
	public void TestFriendRepoGetRecentChats() 
	{
		List<FriendRequest> list = new ArrayList();
		FriendRequest f1 = new FriendRequest();
		FriendRequest f2 = new FriendRequest();
		FriendRequest f3 = new FriendRequest();
		FriendRequest f4 = new FriendRequest();
		
		f1.setId(1);
		f1.setTo("ahmad55");
		f1.setFrom("abdallaa");
		
		f1.setId(2);
		f1.setTo("hsellars");
		f1.setFrom("dnikolic");
		
		f1.setId(3);
		f1.setTo("dnikolic");
		f1.setFrom("abdallaa");
		
		f1.setId(4);
		f1.setTo("hsellars");
		f1.setFrom("abdallaa");
		
		f1.setId(5);
		f1.setTo("ahmad55");
		f1.setFrom("abdallaa");
		
		list.add(f1);
		list.add(f2);
		list.add(f3);
		list.add(f4);
		
		when(repo.getRequestsByTo("ahmad55")).thenReturn(list);
		when(repo.getRequestsByTo("hsellars")).thenReturn(list);
		when(repo.getRequestsByTo("dnikolic")).thenReturn(list);
		when(repo.getRequestsByTo("hsellars")).thenReturn(list);

		assertEquals(list, repo.getRequestsByTo("ahmad55"));
		assertEquals(list, repo.getRequestsByTo("hsellars"));
		assertEquals(list, repo.getRequestsByTo("dnikolic"));
		assertEquals(list, repo.getRequestsByTo("hsellars"));

	}
}