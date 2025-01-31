package org.example;

import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.Transaction;
import org.hibernate.cfg.Configuration;
import org.hibernate.query.SelectionQuery;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import java.util.List;

public class ShapeDAO {
    private static final Logger logger = LoggerFactory.getLogger(ShapeDAO.class);
    private static SessionFactory sessionFactory;

    public static void initializeSessionFactory() {
        try {
            sessionFactory = new Configuration().configure().buildSessionFactory();
            logger.info("SessionFactory initialized successfully.");
        } catch (Exception e) {
            logger.error("Error initializing SessionFactory: {}", e.getMessage(), e);
            throw new ExceptionInInitializerError("SessionFactory initialization failed. See logs for details.");
        }
    }

    public static void initializeSessionFactory(String cfg) {
        try {
            sessionFactory = new Configuration().configure(cfg).buildSessionFactory();
            logger.info("SessionFactory with custom configuration file initialized successfully.");
        } catch (Exception e) {
            logger.error("Error initializing SessionFactory: {}", e.getMessage(), e);
            throw new ExceptionInInitializerError("SessionFactory initialization failed. See logs for details.");
        }
    }

    public static SessionFactory getSessionFactory() {
        if (sessionFactory == null) {
            logger.error("SessionFactory was not initialized.");
            throw new IllegalStateException("SessionFactory is not available. Initialization failed.");
        }
        return sessionFactory;
    }

    public static void shutdown() {
        if (sessionFactory != null) {
            sessionFactory.close();
            logger.info("SessionFactory closed successfully.");
        }
    }
    public ShapeDAO(String cfg) {
        initializeSessionFactory(cfg);
        sessionFactory = getSessionFactory();
    }

    public ShapeDAO() {
        initializeSessionFactory();
        sessionFactory = getSessionFactory();
    }

    public void save(Shape shape) {
        try (Session session = sessionFactory.openSession()) {
            Transaction transaction = session.beginTransaction();
            try {
                session.persist(shape);
                transaction.commit();
            } catch (Exception e) {
                transaction.rollback();
                logger.error("Failed to save shape: {}", shape, e);
            }
        } catch (Exception e) {
            logger.error("Failed to open session for saving shape: {}", shape, e);
        }
    }


    public List<Shape> getAllShapes() {
        try (Session session = sessionFactory.openSession()) {
            SelectionQuery<Shape> query = session.createSelectionQuery("FROM Shape", Shape.class);
            return query.list();
        } catch (Exception e) {
            logger.error("Failed to fetch all shapes", e);
            return List.of();
        }
    }

    public Shape getById(long id) {
        try (Session session = sessionFactory.openSession()) {
            return session.get(Shape.class, id);
        } catch (Exception e) {
            logger.error("Failed to fetch shape with ID: {}", id, e);
            return null;
        }
    }

    public void deleteById(long id) {
        try (Session session = sessionFactory.openSession()) {
            Transaction transaction = session.beginTransaction();
            try {
                Shape shape = session.get(Shape.class, id);
                if (shape != null) {
                    session.remove(shape);
                    transaction.commit();
                    logger.info("Shape with ID {} successfully deleted", id);
                } else {
                    logger.warn("Shape with ID {} not found for deletion", id);
                }
            } catch (Exception e) {
                transaction.rollback();
                logger.error("Failed to delete shape with ID: {}", id, e);
            }
        } catch (Exception e) {
            logger.error("Failed to open session for deleting shape with ID: {}", id, e);
        }
    }

    public void update(Shape shape) {
        Transaction transaction = null;
        try (Session session = sessionFactory.openSession()) {
            transaction = session.beginTransaction();
            session.merge(shape);
            transaction.commit();
            logger.info("Shape '{}' updated successfully.", shape);
        } catch (Exception e) {
            if (transaction != null) transaction.rollback();
            logger.error("Failed to update Shape '{}'. Exception: {}", shape, e.getMessage(), e);
        }
    }
}
